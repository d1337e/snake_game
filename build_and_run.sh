#!/bin/bash

echo "Building..."
mkdir -p build
cd build && cmake .. && make

if [ $? -eq 0 ]; then
    echo "Running..."
    ./snake
else
    echo "Build failed!"
fi