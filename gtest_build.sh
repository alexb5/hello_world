#!/bin/bash

cd /usr/src/gtest
sudo -E cmake CMakeLists.txt
sudo make
sudo cp *.a /usr/lib