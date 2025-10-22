#!/bin/bash

# Check the variable NDK_ROOT is set
if [ -z "$NDK_ROOT" ]; then
	exit 1
fi

$NDK_ROOT/toolchains/llvm/prebuilt/linux-x86_64/bin/aarch64-linux-android35-clang -c func_cpuburn-a53.S -o stress.o
$NDK_ROOT/toolchains/llvm/prebuilt/linux-x86_64/bin/aarch64-linux-android35-clang main.c stress.o -o stress-neon
