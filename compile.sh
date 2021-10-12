#!/bin/bash

cmake -DCMAKE_BUILD_TYPE=Release CMakeLists.txt -Bbuild
cd build
make 

avr-size -C --mcu=aymega8 my_firmware.elf
