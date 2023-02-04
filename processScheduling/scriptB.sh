#!/bin/bash

cd b
make
make -j$(nproc) 