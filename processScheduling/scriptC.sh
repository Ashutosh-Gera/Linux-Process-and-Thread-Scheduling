#!/bin/bash

cd c
make CC="ccache gcc"
make -j$(nproc) CC="ccache gcc" 