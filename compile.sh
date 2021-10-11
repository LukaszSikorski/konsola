#!/bin/bash

cmake -DCMAKE_BUILD_TYPE=Release CMakeLists.txt -Bbuild
cd build
make 