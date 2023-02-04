#!/bin/bash

cd b
make CC="ccache gcc"
make -j$(nproc) CC="ccache gcc" 