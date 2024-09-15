#!/bin/bash

file_name=basic_concept.cpp

rm -rf build/*

# generate ll file
clang++-14 -std=c++17 -S -emit-llvm ${file_name}

#product binary code
clang++-14 -std=c++17 -o basic_concept basic_concept.ll

#generate assambly code
clang++-14 -std=c++17 -S basic_concept.ll 

#execute ll file
lli-14 basic_concept.ll

echo $?


mv basic_concept basic_concept.ll basic_concept.s build/
