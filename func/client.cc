//
//    Pearl Piyawiroj
//    @patriya-piyawiroj
//
#include "client.h"

FuncClient::FuncClient(std::shared_ptr<Channel> channel)
	    : stub_(KeyValueStore::NewStub(channel)) {}

void FuncClient::Hook(const int32_t &event_type, const std::string &event_function) {
  // Data to be sent to server
  HookRequest request;
  HookReply reply;
  request.set_event_type(event_type);
  request.set_event_function(event_function);

  // Context for client
  ClientContext context;

  //RPC
  Status status = stub_->hook(&context, request, &reply);

  // Act upon status
  if (status.ok()) {
    LOG(INFO) << "Hook Successful";
  } else {
    LOG(INFO) << "Hook Failed";
    std::cout  << status.error_code() <<  ": " << status.error_message();
  } 
}

void FuncClient::Unhook(const int32_t &event_type) {
  // Data to be sent to server
  UnhookRequest request;
  UnhookReply reply;
  request.set_event_type(event_type);

  // Context for client
  ClientContext context;

  //RPC
  Status status = stub_->unhook(&context, request, &reply);

  // Act upon status
  if (status.ok()) {
    LOG(INFO) << "Unhook Successful";
  } else {
    LOG(INFO) << "Unhook Failed";
    std::cout  << status.error_code() <<  ": " << status.error_message();
  }
}

google::protobuf::Any Event(const int32_t &event_type, const google::protobuf::Any &payload) {
  // Data to be sent to server 
  EventRequest request;
  EventReply reply;
  request.set_event_type(event_type);
  reqyest.set_payload(payload);

  // Context for client
  ClientContext context;

  // RPC
  Status status = stub_->event(&context, request, &reply);

  // Act upon status
  if (status.ok()) {
    LOG(INFO) << "Unhook Successful";
  } else {                                                                                                       
    LOG(INFO) << "Unhook Failed";               
    std::cout  << status.error_code() <<  ": " << status.error_message();
  }    
  return google::protobuf::Any();
}
