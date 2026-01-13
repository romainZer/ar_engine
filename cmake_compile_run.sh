#!/bin/bash

if [ -d "./build" ]; then
      cd build || exit
else
       mkdir build && cd build || exit
fi

rm -rf ./*
cmake ..
make

./ar_engine