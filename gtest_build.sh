#!/bin/bash

cd /usr/src/gtest
sudo env "PATH=$PATH" cmake CMakeLists.txt
sudo make
sudo cp *.a /usr/lib