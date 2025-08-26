cd build
cmake -G Ninja -DCMAKE_BUILD_TYPE=Debug -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ -DYY_NO_UNISTD_H=ON ../
# cmake --build . --target j0
# cmake --build . --target j0x
# cmake --build .
ninja

cd ..