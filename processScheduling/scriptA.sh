#!/bin/bash

cd a
make CC="ccache gcc"
make -j$(nproc) CC="ccache gcc" 