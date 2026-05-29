#!/bin/bash

METAL_RED="\e[38;2;161;13;10m"
GREEN="\e[38;2;144;205;0m"
RESET="\e[0m"

PROJECT_NAME="IESHA256"
FILE_NAME="build"

clear

mkdir ${FILE_NAME} && cd ${FILE_NAME}

printf "
Compiling ${METAL_RED}${PROJECT_NAME}${RESET} With Cmake...\n\n"

cmake -DCMAKE_BUILD_TYPE=Release ..

printf "
Building ${METAL_RED}${PROJECT_NAME}${RESET}...\n\n"

make -j$(nproc)

printf "
[ ${GREEN}OK${RESET}] - Build Finished Successfully!!!\n\n"
