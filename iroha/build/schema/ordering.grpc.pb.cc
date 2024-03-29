// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: ordering.proto

#include "ordering.pb.h"
#include "ordering.grpc.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/channel_interface.h>
#include <grpcpp/impl/codegen/client_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/rpc_service_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/sync_stream.h>
namespace iroha {
namespace ordering {
namespace proto {

static const char* OrderingGateTransportGrpc_method_names[] = {
  "/iroha.ordering.proto.OrderingGateTransportGrpc/onProposal",
};

std::unique_ptr< OrderingGateTransportGrpc::Stub> OrderingGateTransportGrpc::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< OrderingGateTransportGrpc::Stub> stub(new OrderingGateTransportGrpc::Stub(channel));
  return stub;
}

OrderingGateTransportGrpc::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel)
  : channel_(channel), rpcmethod_onProposal_(OrderingGateTransportGrpc_method_names[0], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status OrderingGateTransportGrpc::Stub::onProposal(::grpc::ClientContext* context, const ::iroha::protocol::Proposal& request, ::google::protobuf::Empty* response) {
  return ::grpc::internal::BlockingUnaryCall< ::iroha::protocol::Proposal, ::google::protobuf::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_onProposal_, context, request, response);
}

void OrderingGateTransportGrpc::Stub::experimental_async::onProposal(::grpc::ClientContext* context, const ::iroha::protocol::Proposal* request, ::google::protobuf::Empty* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::iroha::protocol::Proposal, ::google::protobuf::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_onProposal_, context, request, response, std::move(f));
}

void OrderingGateTransportGrpc::Stub::experimental_async::onProposal(::grpc::ClientContext* context, const ::iroha::protocol::Proposal* request, ::google::protobuf::Empty* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_onProposal_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::google::protobuf::Empty>* OrderingGateTransportGrpc::Stub::PrepareAsynconProposalRaw(::grpc::ClientContext* context, const ::iroha::protocol::Proposal& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::google::protobuf::Empty, ::iroha::protocol::Proposal, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_onProposal_, context, request);
}

::grpc::ClientAsyncResponseReader< ::google::protobuf::Empty>* OrderingGateTransportGrpc::Stub::AsynconProposalRaw(::grpc::ClientContext* context, const ::iroha::protocol::Proposal& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsynconProposalRaw(context, request, cq);
  result->StartCall();
  return result;
}

OrderingGateTransportGrpc::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      OrderingGateTransportGrpc_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< OrderingGateTransportGrpc::Service, ::iroha::protocol::Proposal, ::google::protobuf::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](OrderingGateTransportGrpc::Service* service,
             ::grpc::ServerContext* ctx,
             const ::iroha::protocol::Proposal* req,
             ::google::protobuf::Empty* resp) {
               return service->onProposal(ctx, req, resp);
             }, this)));
}

OrderingGateTransportGrpc::Service::~Service() {
}

::grpc::Status OrderingGateTransportGrpc::Service::onProposal(::grpc::ServerContext* context, const ::iroha::protocol::Proposal* request, ::google::protobuf::Empty* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


static const char* OrderingServiceTransportGrpc_method_names[] = {
  "/iroha.ordering.proto.OrderingServiceTransportGrpc/onBatch",
};

std::unique_ptr< OrderingServiceTransportGrpc::Stub> OrderingServiceTransportGrpc::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< OrderingServiceTransportGrpc::Stub> stub(new OrderingServiceTransportGrpc::Stub(channel));
  return stub;
}

OrderingServiceTransportGrpc::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel)
  : channel_(channel), rpcmethod_onBatch_(OrderingServiceTransportGrpc_method_names[0], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status OrderingServiceTransportGrpc::Stub::onBatch(::grpc::ClientContext* context, const ::iroha::protocol::TxList& request, ::google::protobuf::Empty* response) {
  return ::grpc::internal::BlockingUnaryCall< ::iroha::protocol::TxList, ::google::protobuf::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_onBatch_, context, request, response);
}

void OrderingServiceTransportGrpc::Stub::experimental_async::onBatch(::grpc::ClientContext* context, const ::iroha::protocol::TxList* request, ::google::protobuf::Empty* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::iroha::protocol::TxList, ::google::protobuf::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_onBatch_, context, request, response, std::move(f));
}

void OrderingServiceTransportGrpc::Stub::experimental_async::onBatch(::grpc::ClientContext* context, const ::iroha::protocol::TxList* request, ::google::protobuf::Empty* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_onBatch_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::google::protobuf::Empty>* OrderingServiceTransportGrpc::Stub::PrepareAsynconBatchRaw(::grpc::ClientContext* context, const ::iroha::protocol::TxList& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::google::protobuf::Empty, ::iroha::protocol::TxList, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_onBatch_, context, request);
}

::grpc::ClientAsyncResponseReader< ::google::protobuf::Empty>* OrderingServiceTransportGrpc::Stub::AsynconBatchRaw(::grpc::ClientContext* context, const ::iroha::protocol::TxList& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsynconBatchRaw(context, request, cq);
  result->StartCall();
  return result;
}

OrderingServiceTransportGrpc::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      OrderingServiceTransportGrpc_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< OrderingServiceTransportGrpc::Service, ::iroha::protocol::TxList, ::google::protobuf::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](OrderingServiceTransportGrpc::Service* service,
             ::grpc::ServerContext* ctx,
             const ::iroha::protocol::TxList* req,
             ::google::protobuf::Empty* resp) {
               return service->onBatch(ctx, req, resp);
             }, this)));
}

OrderingServiceTransportGrpc::Service::~Service() {
}

::grpc::Status OrderingServiceTransportGrpc::Service::onBatch(::grpc::ServerContext* context, const ::iroha::protocol::TxList* request, ::google::protobuf::Empty* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


static const char* OnDemandOrdering_method_names[] = {
  "/iroha.ordering.proto.OnDemandOrdering/SendBatches",
  "/iroha.ordering.proto.OnDemandOrdering/RequestProposal",
};

std::unique_ptr< OnDemandOrdering::Stub> OnDemandOrdering::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< OnDemandOrdering::Stub> stub(new OnDemandOrdering::Stub(channel));
  return stub;
}

OnDemandOrdering::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel)
  : channel_(channel), rpcmethod_SendBatches_(OnDemandOrdering_method_names[0], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_RequestProposal_(OnDemandOrdering_method_names[1], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status OnDemandOrdering::Stub::SendBatches(::grpc::ClientContext* context, const ::iroha::ordering::proto::BatchesRequest& request, ::google::protobuf::Empty* response) {
  return ::grpc::internal::BlockingUnaryCall< ::iroha::ordering::proto::BatchesRequest, ::google::protobuf::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_SendBatches_, context, request, response);
}

void OnDemandOrdering::Stub::experimental_async::SendBatches(::grpc::ClientContext* context, const ::iroha::ordering::proto::BatchesRequest* request, ::google::protobuf::Empty* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::iroha::ordering::proto::BatchesRequest, ::google::protobuf::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_SendBatches_, context, request, response, std::move(f));
}

void OnDemandOrdering::Stub::experimental_async::SendBatches(::grpc::ClientContext* context, const ::iroha::ordering::proto::BatchesRequest* request, ::google::protobuf::Empty* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_SendBatches_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::google::protobuf::Empty>* OnDemandOrdering::Stub::PrepareAsyncSendBatchesRaw(::grpc::ClientContext* context, const ::iroha::ordering::proto::BatchesRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::google::protobuf::Empty, ::iroha::ordering::proto::BatchesRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_SendBatches_, context, request);
}

::grpc::ClientAsyncResponseReader< ::google::protobuf::Empty>* OnDemandOrdering::Stub::AsyncSendBatchesRaw(::grpc::ClientContext* context, const ::iroha::ordering::proto::BatchesRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncSendBatchesRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status OnDemandOrdering::Stub::RequestProposal(::grpc::ClientContext* context, const ::iroha::ordering::proto::ProposalRequest& request, ::iroha::ordering::proto::ProposalResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::iroha::ordering::proto::ProposalRequest, ::iroha::ordering::proto::ProposalResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_RequestProposal_, context, request, response);
}

void OnDemandOrdering::Stub::experimental_async::RequestProposal(::grpc::ClientContext* context, const ::iroha::ordering::proto::ProposalRequest* request, ::iroha::ordering::proto::ProposalResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::iroha::ordering::proto::ProposalRequest, ::iroha::ordering::proto::ProposalResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_RequestProposal_, context, request, response, std::move(f));
}

void OnDemandOrdering::Stub::experimental_async::RequestProposal(::grpc::ClientContext* context, const ::iroha::ordering::proto::ProposalRequest* request, ::iroha::ordering::proto::ProposalResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_RequestProposal_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::iroha::ordering::proto::ProposalResponse>* OnDemandOrdering::Stub::PrepareAsyncRequestProposalRaw(::grpc::ClientContext* context, const ::iroha::ordering::proto::ProposalRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::iroha::ordering::proto::ProposalResponse, ::iroha::ordering::proto::ProposalRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_RequestProposal_, context, request);
}

::grpc::ClientAsyncResponseReader< ::iroha::ordering::proto::ProposalResponse>* OnDemandOrdering::Stub::AsyncRequestProposalRaw(::grpc::ClientContext* context, const ::iroha::ordering::proto::ProposalRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncRequestProposalRaw(context, request, cq);
  result->StartCall();
  return result;
}

OnDemandOrdering::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      OnDemandOrdering_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< OnDemandOrdering::Service, ::iroha::ordering::proto::BatchesRequest, ::google::protobuf::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](OnDemandOrdering::Service* service,
             ::grpc::ServerContext* ctx,
             const ::iroha::ordering::proto::BatchesRequest* req,
             ::google::protobuf::Empty* resp) {
               return service->SendBatches(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      OnDemandOrdering_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< OnDemandOrdering::Service, ::iroha::ordering::proto::ProposalRequest, ::iroha::ordering::proto::ProposalResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](OnDemandOrdering::Service* service,
             ::grpc::ServerContext* ctx,
             const ::iroha::ordering::proto::ProposalRequest* req,
             ::iroha::ordering::proto::ProposalResponse* resp) {
               return service->RequestProposal(ctx, req, resp);
             }, this)));
}

OnDemandOrdering::Service::~Service() {
}

::grpc::Status OnDemandOrdering::Service::SendBatches(::grpc::ServerContext* context, const ::iroha::ordering::proto::BatchesRequest* request, ::google::protobuf::Empty* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status OnDemandOrdering::Service::RequestProposal(::grpc::ServerContext* context, const ::iroha::ordering::proto::ProposalRequest* request, ::iroha::ordering::proto::ProposalResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace iroha
}  // namespace ordering
}  // namespace proto

