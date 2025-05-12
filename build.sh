#!/bin/bash
set -e

mkdir -p build
cd build

cmake ..

cmake --build .

if [ "$1" == "--test" ]; then
    echo "Running tests..."
    ctest --output-on-failure
fi

echo "Build completed successfully!"
