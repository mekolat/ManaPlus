#!/bin/bash

function run {
    echo "running pipeline for $1"
    curl --request POST --form "token=$BUILD_TRIGGER" --form ref=$1 https://gitlab.com/api/v4/projects/180398/trigger/pipeline || exit 1
}

run "ci_deheader"
sleep 15s
run "ci_gcc4x"
sleep 15s
run "ci_gcc49"
sleep 15s
run "ci_clang3x"
sleep 15s
run "ci_customnls"
sleep 15s
run "ci_clang-tidy"
sleep 15s
run "ci_h"
sleep 15s
run "ci_gcc6_tests"
sleep 15s
run "ci_gcc6"
sleep 15s
run "ci_malloc"