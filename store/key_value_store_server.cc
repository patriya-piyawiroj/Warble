//
//    Pearl Piyawiroj
//    @patriya-piyawiroj
//
#include "key_value_store_server.h"

Status KvstoreServiceImpl::put(ServerContext* context, const PutRequest* request, PutReply* reply) {
  std::string key = request->key();
  std::string value = request->value();
  if (!filename_.empty()) {
    CreateKeyFile(key, value, filename_);
  }
  map_.put(key, value);
  LOG(INFO) << "Putting in " << key;
  return Status::OK;
}

Status KvstoreServiceImpl::get(ServerContext* context, const GetRequest* request, GetReply* reply) {
  std::optional<std::string> opt = map_.get(request->key());
  if (opt.has_value()) {
    reply->set_value(opt.value());
    return Status::OK;
  } else {
    return Status(StatusCode::NOT_FOUND, "GetRequest unsuccessful");
  }
}

Status KvstoreServiceImpl::remove(ServerContext* context, const RemoveRequest* request, RemoveReply* reply) {
  bool removed = map_.remove(request->key());
  if (removed) {
    return Status::OK;
  } else {
    return grpc::Status(grpc::StatusCode::NOT_FOUND, "RemoveRequest unsuccessful");
  }
}

void KvstoreServiceImpl::CreateKeyFile(const std::string &key, const std::string &value, const std::string &filename){
  std::ifstream infile(filename) ;
  if (!infile.is_open()){
    std::ofstream myfile;
    myfile.open(filename, std::ios_base::app);
    myfile << key << ":" << value << "\n";
    myfile.close();
  } else {
    std::fstream infile(filename);
    std::string line;
    std::string delimiter = ":";
    int i = 0;
    while(std::getline(infile, line)){
      i++;
      std::string first = line.substr(0,line.find(delimiter));
      std::string second = line.substr(line.find(delimiter)+1, line.length());
      if (key.compare(first)==0){
        LOG(INFO) << "FOUND SAME USER";
        Deleteline(first, i);
        Writeline(first, key, value);
        return;
      }
    }
    Writeline(filename, key, value); 
  }
}

void KvstoreServiceImpl::Writeline(const std::string &file_name, const std::string &key, const std::string &val){
  std::ofstream ofs;
  ofs.open(file_name, std::ios_base::app);
  ofs << key << ":" << val << "\n";
  ofs.close();
}

void KvstoreServiceImpl::Deleteline(const std::string &file_name, int n) { 
    std::ifstream is(file_name); 
    std::ofstream ofs; 
    ofs.open("temp.txt", std::ofstream::out); 
    char c; 
    int line_no = 1; 
    while (is.get(c)) { 
        if (c == '\n') 
        line_no++; 
        if (line_no != n) 
            ofs << c; 
    } 
    ofs.close(); 
    is.close(); 
    //std method of remove requires char * //
    const char * filename = file_name.c_str();
    std::remove(filename); 
    std::rename("temp.txt", filename); 
} 


void RunServer(std::string filename) {
  std::string server_address("localhost:50001");
  KvstoreServiceImpl service;

  if (!filename.empty()) {
    service.filename_ = filename;
  } 
	

  ServerBuilder builder;
  builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
  builder.RegisterService(&service);
  std::unique_ptr<Server> server(builder.BuildAndStart());
  std::cout << "Server listening on " << server_address << std::endl;
  LOG(INFO) << "Server waiting";
  server->Wait();
  server->Shutdown();
}

int main(int argc, char* argv[]) {
  google::ParseCommandLineFlags(&argc, &argv, true);
  if (!FLAGS_store.empty()){
    std::string filename(FLAGS_store);
    RunServer(filename);
  } else {	  
    RunServer(std::string()) ;
  }
  return 0;
}
