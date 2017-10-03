/**
 * Autogenerated by Thrift Compiler (0.10.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef PhashServer_H
#define PhashServer_H

#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include "wal_types.h"



#ifdef _WIN32
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class PhashServerIf {
 public:
  virtual ~PhashServerIf() {}
  virtual void ping(Ping_ACK& _return) = 0;
  virtual void submit_ops(ClientOpsRetval& _return, const ClientOps& ops) = 0;
};

class PhashServerIfFactory {
 public:
  typedef PhashServerIf Handler;

  virtual ~PhashServerIfFactory() {}

  virtual PhashServerIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(PhashServerIf* /* handler */) = 0;
};

class PhashServerIfSingletonFactory : virtual public PhashServerIfFactory {
 public:
  PhashServerIfSingletonFactory(const boost::shared_ptr<PhashServerIf>& iface) : iface_(iface) {}
  virtual ~PhashServerIfSingletonFactory() {}

  virtual PhashServerIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(PhashServerIf* /* handler */) {}

 protected:
  boost::shared_ptr<PhashServerIf> iface_;
};

class PhashServerNull : virtual public PhashServerIf {
 public:
  virtual ~PhashServerNull() {}
  void ping(Ping_ACK& /* _return */) {
    return;
  }
  void submit_ops(ClientOpsRetval& /* _return */, const ClientOps& /* ops */) {
    return;
  }
};


class PhashServer_ping_args {
 public:

  PhashServer_ping_args(const PhashServer_ping_args&);
  PhashServer_ping_args& operator=(const PhashServer_ping_args&);
  PhashServer_ping_args() {
  }

  virtual ~PhashServer_ping_args() throw();

  bool operator == (const PhashServer_ping_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const PhashServer_ping_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const PhashServer_ping_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class PhashServer_ping_pargs {
 public:


  virtual ~PhashServer_ping_pargs() throw();

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _PhashServer_ping_result__isset {
  _PhashServer_ping_result__isset() : success(false) {}
  bool success :1;
} _PhashServer_ping_result__isset;

class PhashServer_ping_result {
 public:

  PhashServer_ping_result(const PhashServer_ping_result&);
  PhashServer_ping_result& operator=(const PhashServer_ping_result&);
  PhashServer_ping_result() {
  }

  virtual ~PhashServer_ping_result() throw();
  Ping_ACK success;

  _PhashServer_ping_result__isset __isset;

  void __set_success(const Ping_ACK& val);

  bool operator == (const PhashServer_ping_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const PhashServer_ping_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const PhashServer_ping_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _PhashServer_ping_presult__isset {
  _PhashServer_ping_presult__isset() : success(false) {}
  bool success :1;
} _PhashServer_ping_presult__isset;

class PhashServer_ping_presult {
 public:


  virtual ~PhashServer_ping_presult() throw();
  Ping_ACK* success;

  _PhashServer_ping_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _PhashServer_submit_ops_args__isset {
  _PhashServer_submit_ops_args__isset() : ops(false) {}
  bool ops :1;
} _PhashServer_submit_ops_args__isset;

class PhashServer_submit_ops_args {
 public:

  PhashServer_submit_ops_args(const PhashServer_submit_ops_args&);
  PhashServer_submit_ops_args& operator=(const PhashServer_submit_ops_args&);
  PhashServer_submit_ops_args() {
  }

  virtual ~PhashServer_submit_ops_args() throw();
  ClientOps ops;

  _PhashServer_submit_ops_args__isset __isset;

  void __set_ops(const ClientOps& val);

  bool operator == (const PhashServer_submit_ops_args & rhs) const
  {
    if (!(ops == rhs.ops))
      return false;
    return true;
  }
  bool operator != (const PhashServer_submit_ops_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const PhashServer_submit_ops_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class PhashServer_submit_ops_pargs {
 public:


  virtual ~PhashServer_submit_ops_pargs() throw();
  const ClientOps* ops;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _PhashServer_submit_ops_result__isset {
  _PhashServer_submit_ops_result__isset() : success(false) {}
  bool success :1;
} _PhashServer_submit_ops_result__isset;

class PhashServer_submit_ops_result {
 public:

  PhashServer_submit_ops_result(const PhashServer_submit_ops_result&);
  PhashServer_submit_ops_result& operator=(const PhashServer_submit_ops_result&);
  PhashServer_submit_ops_result() {
  }

  virtual ~PhashServer_submit_ops_result() throw();
  ClientOpsRetval success;

  _PhashServer_submit_ops_result__isset __isset;

  void __set_success(const ClientOpsRetval& val);

  bool operator == (const PhashServer_submit_ops_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const PhashServer_submit_ops_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const PhashServer_submit_ops_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _PhashServer_submit_ops_presult__isset {
  _PhashServer_submit_ops_presult__isset() : success(false) {}
  bool success :1;
} _PhashServer_submit_ops_presult__isset;

class PhashServer_submit_ops_presult {
 public:


  virtual ~PhashServer_submit_ops_presult() throw();
  ClientOpsRetval* success;

  _PhashServer_submit_ops_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class PhashServerClient : virtual public PhashServerIf {
 public:
  PhashServerClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  PhashServerClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void ping(Ping_ACK& _return);
  void send_ping();
  void recv_ping(Ping_ACK& _return);
  void submit_ops(ClientOpsRetval& _return, const ClientOps& ops);
  void send_submit_ops(const ClientOps& ops);
  void recv_submit_ops(ClientOpsRetval& _return);
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class PhashServerProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<PhashServerIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (PhashServerProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_ping(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_submit_ops(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  PhashServerProcessor(boost::shared_ptr<PhashServerIf> iface) :
    iface_(iface) {
    processMap_["ping"] = &PhashServerProcessor::process_ping;
    processMap_["submit_ops"] = &PhashServerProcessor::process_submit_ops;
  }

  virtual ~PhashServerProcessor() {}
};

class PhashServerProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  PhashServerProcessorFactory(const ::boost::shared_ptr< PhashServerIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< PhashServerIfFactory > handlerFactory_;
};

class PhashServerMultiface : virtual public PhashServerIf {
 public:
  PhashServerMultiface(std::vector<boost::shared_ptr<PhashServerIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~PhashServerMultiface() {}
 protected:
  std::vector<boost::shared_ptr<PhashServerIf> > ifaces_;
  PhashServerMultiface() {}
  void add(boost::shared_ptr<PhashServerIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void ping(Ping_ACK& _return) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->ping(_return);
    }
    ifaces_[i]->ping(_return);
    return;
  }

  void submit_ops(ClientOpsRetval& _return, const ClientOps& ops) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->submit_ops(_return, ops);
    }
    ifaces_[i]->submit_ops(_return, ops);
    return;
  }

};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
class PhashServerConcurrentClient : virtual public PhashServerIf {
 public:
  PhashServerConcurrentClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  PhashServerConcurrentClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void ping(Ping_ACK& _return);
  int32_t send_ping();
  void recv_ping(Ping_ACK& _return, const int32_t seqid);
  void submit_ops(ClientOpsRetval& _return, const ClientOps& ops);
  int32_t send_submit_ops(const ClientOps& ops);
  void recv_submit_ops(ClientOpsRetval& _return, const int32_t seqid);
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
  ::apache::thrift::async::TConcurrentClientSyncInfo sync_;
};

#ifdef _WIN32
  #pragma warning( pop )
#endif



#endif
