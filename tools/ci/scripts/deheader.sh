#!/bin/bash

export var=$1
export name=${var%.*}
export name=${name#./src/}
export name=${name##*./}.h
export dir=$(pwd)

echo $1 >>${LOGFILE}
echo $1

${dir}/deheader -q -i "\"debug.h\"" \
-i "\"utils/checkutils.h\"" \
-i "\"utils/sdlcheckutils.h\"" \
-i "\"sdlshared.h\"" \
-i "\"localconsts.h\"" \
-i "\"utils/fuzzer.h\"" \
-i "\"utils/physfscheckutils.h\"" \
-i "\"$name\"" \
-c "$CXX" \
-d "$FLAGS" \
-m "-c -std=gnu++1z -Werror -Wall -Wextra -Wundef -Wmissing-declarations -DLOCALEDIR=\\\"\\\" -I/usr/include $INCLUDES -I${dir}/src" $1 \
| grep -v "portability requires" | tee -a ${LOGFILE}