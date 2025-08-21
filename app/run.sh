#!/usr/bin/env bash
set -e  # exit if any command fails

file_name="cv_qualifier_four.cpp"
build_dir="build"

# Remove old build directory if it exists
rm -rf "$build_dir"

# Create a fresh build directory
mkdir -p "$build_dir"
cd "$build_dir"

# Generate LLVM IR (.ll)
clang++-14 -std=c++20 -S -emit-llvm "../${file_name}" -o program.ll

# Produce binary code
clang++-14 -std=c++20 -o program program.ll

# Generate assembly code (.s)
clang++-14 -std=c++20 -S program.ll -o program.s

# Execute LLVM IR with lli
lli-14 program.ll

# Print program exit code
echo "Exit code: $?"
