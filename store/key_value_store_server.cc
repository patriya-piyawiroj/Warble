#include "key_value_store_server.h"
#include <fstream>
#include <string.h> 
#include <algorithm>
#include <bits/stdc++.h> 

Status KvstoreServiceImpl::put(ServerContext* context, const PutRequest* request, PutReply* reply) {
  std::string key = request->key();
  std::string value = request->value();
  CreateKeyFile(key, value);
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

bool KvstoreServiceImpl::fileExists(const char *fileName)
{
    std::ifstream infile(fileName);
    return infile.good();
}

void KvstoreServiceImpl::CreateKeyFile(const std::string &key, const std::string &value){
  if (!fileExists("key-pair.txt")){
    std::ofstream myfile;
    myfile.open("key-pair.txt", std::ios_base::app);
    myfile << key << ":" << value << "\n";
    myfile.close();
  } else {
    std::fstream infile("key-pair.txt");
    std::string line;
    std::string delimiter = ":";
    int i = 0;
    const char * v = value.c_str();
    const char * k = key.c_str();
    while(std::getline(infile, line)){
      i++;
      std::string first = line.substr(0,line.find(delimiter));
      std::string second = line.substr(line.find(delimiter)+1, line.length());
      const char * f = first.c_str();
      if (strcmp(k,f)==0){
        LOG(INFO) << "FOUND SAME USER";
        Deleteline("key-pair.txt", i);
        Writeline("key-pair.txt",k, v);
        return;
      }
    }
    Writeline("key-pair.txt",k, v); 
  }
}

void KvstoreServiceImpl::Writeline(const char *file_name, const char *key, const char *val){
  std::ofstream ofs;
  ofs.open(file_name, std::ios_base::app);
  ofs << key << ":" << val << "\n";
  ofs.close();
}

void KvstoreServiceImpl::Deleteline(const char *file_name, int n) { 
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
    std::remove(file_name); 
    std::rename("temp.txt", file_name); 
} 


void RunServer() {
  std::string server_address("localhost:50001");
  KvstoreServiceImpl service;

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
  RunServer();
  return 0;
}