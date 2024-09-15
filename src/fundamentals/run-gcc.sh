#!/bin/bash

file_name=memory/heap_memory.cpp

rm -rf build/*

g++ -std=c++17 ${file_name} -o program

mv program build/

valgrind --leak-check=full build/program
