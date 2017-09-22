#!/usr/local/bin/thrift --gen cpp

namespace cpp Test


struct Ops {
	1: i32 num,
	2: string key,
	3: string value,
	4: string address,
}

struct Ops_ACK {
	1: i32 errnum,
	2: string errMsg,
}

service Something {
  i32 ping(),

  i32 send_ops(1: Ops passed_value, 2: Ops_ACK retval),

}
