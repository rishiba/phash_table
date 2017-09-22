#!/bin/bash
make -f makefile.thrift


LD_LIBRARY_PATH="/home/rishi/thrift-0.10.0/lib/cpp/.libs/"

export LD_LIBRARY_PATH="/usr/lib":${LD_LIBRARY_PATH}

./something_client
