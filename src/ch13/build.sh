#!/usr/bin/bash
cd build
cmake -G Ninja -DCMAKE_BUILD_TYPE=Debug -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ ../
# cmake --build . --target j0
# cmake --build . --target j0x
# cmake --build .
ninja

cd ..