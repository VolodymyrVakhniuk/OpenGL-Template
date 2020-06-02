#!/bin/bash

mkdir -p bin
cd bin 
mkdir -p release

cd release
cmake -DCMAKE_BUILD_TYPE=Release ../..
make
echo "Built target in bin/release/"

