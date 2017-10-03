#! /bin/bash
# https://wiki.apache.org/thrift/ThriftUsageC%2B%2B

rm -rf gen-cpp
thrift --gen cpp wal.thirft
