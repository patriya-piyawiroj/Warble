//
//    Pearl Piyawiroj
//    @patriya-piyawiroj
//
#include "kvstore_client.h"

KvstoreClient::KvstoreClient(std::shared_ptr<Channel> channel)
    : stub_(KeyValueStore::NewStub(channel)) {}


void KvstoreClient::Put(const std::string& key, const std::string& value, const std::optional<std::string>& filename) {
  // Data to be sent to server
  PutRequest request;
  request.set_key(key);
  request.set_value(value);
  if (filename.has_value()) {
    request.set_filename(filename.value());
  } else {
    request.set_filename(std::string());
  }

  // Container for reply
  PutReply reply;

  // Context for client 
  ClientContext context;

  // RPC
  LOG(INFO) << "Starting RPC";
  Status status = stub_->put(&context, request, &reply);

  // Act upon status
  if (status.ok()) {
    LOG(INFO) << "Put Successful";
    return;
  } else {
    LOG(INFO) << "Put Failed";
    std::cout  << status.error_code() <<  ": " << status.error_message();
    return;
  }
}

std::optional<std::string> KvstoreClient::Get(const std::string& key) {
  ClientContext context;

  std::shared_ptr<ClientReaderWriter<GetRequest, GetReply> > stream (
    stub_->get(&context));
  GetRequest request;
  request.set_key(key);
  stream->Write(request);
  stream->WritesDone();
  std::thread writer([stream]() {
  });
  GetReply reply;
  while (stream->Read(&reply)) {}
  writer.join();
  Status status = stream->Finish();

  // Act upon status
  if (status.ok()) {
    return reply.value();
  } else {
    std::cout << status.error_code() <<  ": " << status.error_message() << std::endl;
    return std::nullopt;
  }
}

void KvstoreClient::Remove(const std::string& key) {
  // Data to be sent to server
  RemoveRequest request;
  request.set_key(key);

  // Container for reply
  RemoveReply reply;

  // Context for client
  ClientContext context;

  // RPC
  Status status = stub_->remove(&context, request, &reply);

  // Act upon status
  if (status.ok()) {
    return;
  } else {
    std::cout << status.error_code() <<  ": " << status.error_message() << std::endl;
    return;
  }
}
