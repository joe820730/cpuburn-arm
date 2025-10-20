#!/bin/bash

# Check the variable NDK_ROOT is set
if [ -z "$NDK_ROOT" ]; then
	exit 1
fi

$NDK_ROOT/toolchains/llvm/prebuilt/linux-x86_64/bin/aarch64-linux-android35-clang cpuburn-a53.S -o stress-neon
