#include "kvstore_client.h"

class KvstoreClient {

KvstoreClien::KvstoreClient(std::shared_ptr<Channel> channel)
    : stub_(KeyValueStore::NewStub(channel)) {}

void KvstoreClient::Put(const std::string& key, const std::string& value) {
  // Data to be sent to server
  PutRequest request;
  request.set_key(key);

  // Container for reply
  PutReply reply;

  // Context for client 
  ClientContext context;

  // RPC
  Status status = stub_->put(&context, request, &reply);

  // Act upon status
  if (status.ok()) {
    return;
  } else {
    std::cout << status.error_code() <<  ": " << status.error_message() << std::endl;
    return;
  }
}

std::optional<string> KvstoreClient::Get(const std::string& key) {
  // Data to be sent to server
  GetRequest request;
  request.set_key(key);

  // Container for reply
  GetReply reply;

  // Context for client
  ClientContext context;

  // RPC
  Status status = stub_->get(&context, request, &reply);

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
