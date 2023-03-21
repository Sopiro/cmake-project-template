rm -rf build
mkdir build
cd build
CC=/usr/bin/gcc
CXX=/usr/bin/g++
cmake ..
cmake --build .
