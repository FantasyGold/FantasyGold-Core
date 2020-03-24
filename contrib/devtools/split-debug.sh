#!/bin/sh
set -e
if [ $# -ne 3 ];
    then echo "usage: $0 <input> <stripped-binary> <debug-binary>"
fi

/usr/bin/aarch64-linux-gnu-objcopy --enable-deterministic-archives -p --only-keep-debug $1 $3
/usr/bin/aarch64-linux-gnu-objcopy --enable-deterministic-archives -p --strip-debug $1 $2
/usr/bin/aarch64-linux-gnu-strip --enable-deterministic-archives -p -s $2
/usr/bin/aarch64-linux-gnu-objcopy --enable-deterministic-archives -p --add-gnu-debuglink=$3 $2
