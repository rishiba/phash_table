/**
 * Autogenerated by Thrift Compiler (0.10.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "wal_types.h"

#include <algorithm>
#include <ostream>

#include <thrift/TToString.h>




ClientOps::~ClientOps() throw() {
}


void ClientOps::__set_op_type(const int32_t val) {
  this->op_type = val;
}

void ClientOps::__set_key(const std::string& val) {
  this->key = val;
}

void ClientOps::__set_value(const std::string& val) {
  this->value = val;
}

uint32_t ClientOps::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->op_type);
          this->__isset.op_type = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->key);
          this->__isset.key = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->value);
          this->__isset.value = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t ClientOps::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ClientOps");

  xfer += oprot->writeFieldBegin("op_type", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32(this->op_type);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("key", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->key);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("value", ::apache::thrift::protocol::T_STRING, 3);
  xfer += oprot->writeString(this->value);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(ClientOps &a, ClientOps &b) {
  using ::std::swap;
  swap(a.op_type, b.op_type);
  swap(a.key, b.key);
  swap(a.value, b.value);
  swap(a.__isset, b.__isset);
}

ClientOps::ClientOps(const ClientOps& other0) {
  op_type = other0.op_type;
  key = other0.key;
  value = other0.value;
  __isset = other0.__isset;
}
ClientOps& ClientOps::operator=(const ClientOps& other1) {
  op_type = other1.op_type;
  key = other1.key;
  value = other1.value;
  __isset = other1.__isset;
  return *this;
}
void ClientOps::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "ClientOps(";
  out << "op_type=" << to_string(op_type);
  out << ", " << "key=" << to_string(key);
  out << ", " << "value=" << to_string(value);
  out << ")";
}


ClientOpsRetval::~ClientOpsRetval() throw() {
}


void ClientOpsRetval::__set_errNo(const int32_t val) {
  this->errNo = val;
}

void ClientOpsRetval::__set_key(const std::string& val) {
  this->key = val;
}

void ClientOpsRetval::__set_value(const std::string& val) {
  this->value = val;
}

uint32_t ClientOpsRetval::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->errNo);
          this->__isset.errNo = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->key);
          this->__isset.key = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->value);
          this->__isset.value = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t ClientOpsRetval::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ClientOpsRetval");

  xfer += oprot->writeFieldBegin("errNo", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32(this->errNo);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("key", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->key);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("value", ::apache::thrift::protocol::T_STRING, 3);
  xfer += oprot->writeString(this->value);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(ClientOpsRetval &a, ClientOpsRetval &b) {
  using ::std::swap;
  swap(a.errNo, b.errNo);
  swap(a.key, b.key);
  swap(a.value, b.value);
  swap(a.__isset, b.__isset);
}

ClientOpsRetval::ClientOpsRetval(const ClientOpsRetval& other2) {
  errNo = other2.errNo;
  key = other2.key;
  value = other2.value;
  __isset = other2.__isset;
}
ClientOpsRetval& ClientOpsRetval::operator=(const ClientOpsRetval& other3) {
  errNo = other3.errNo;
  key = other3.key;
  value = other3.value;
  __isset = other3.__isset;
  return *this;
}
void ClientOpsRetval::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "ClientOpsRetval(";
  out << "errNo=" << to_string(errNo);
  out << ", " << "key=" << to_string(key);
  out << ", " << "value=" << to_string(value);
  out << ")";
}


Ping_ACK::~Ping_ACK() throw() {
}


void Ping_ACK::__set_errNo(const int32_t val) {
  this->errNo = val;
}

void Ping_ACK::__set_errMsg(const std::string& val) {
  this->errMsg = val;
}

uint32_t Ping_ACK::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->errNo);
          this->__isset.errNo = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->errMsg);
          this->__isset.errMsg = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t Ping_ACK::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("Ping_ACK");

  xfer += oprot->writeFieldBegin("errNo", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32(this->errNo);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("errMsg", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->errMsg);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(Ping_ACK &a, Ping_ACK &b) {
  using ::std::swap;
  swap(a.errNo, b.errNo);
  swap(a.errMsg, b.errMsg);
  swap(a.__isset, b.__isset);
}

Ping_ACK::Ping_ACK(const Ping_ACK& other4) {
  errNo = other4.errNo;
  errMsg = other4.errMsg;
  __isset = other4.__isset;
}
Ping_ACK& Ping_ACK::operator=(const Ping_ACK& other5) {
  errNo = other5.errNo;
  errMsg = other5.errMsg;
  __isset = other5.__isset;
  return *this;
}
void Ping_ACK::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "Ping_ACK(";
  out << "errNo=" << to_string(errNo);
  out << ", " << "errMsg=" << to_string(errMsg);
  out << ")";
}

