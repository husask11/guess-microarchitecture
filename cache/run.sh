#!/bin/bash

echo "======================================"
echo "Step0. Compile"
echo "======================================"

sleep 3
make

echo "==========================================================================="
echo "Step1. Test memory access time to guess cache size"
echo "==========================================================================="
sleep 2
./cache -T 2

echo "==========================================================================="
echo "Step2. Allocate linear memory spaces"
echo "       and access each memory with different stride (it takes a few minute)"
echo "==========================================================================="

echo "   - Memory (from 2KB to 32MB) -"
echo "   - Stride (from 8B to 16MB)   -"
echo "   - If you want to print full log, please set CACHE_DEBUG to 1 in config.h"

sleep 3
./cache -T 1

echo "======================================"
echo "Step3. Start draw a graph"
echo "======================================"
sleep 2

./plot.sh
./plot2.sh

echo "my_plot, my_plot2, my_plot3.png files are generated"

display "my_plot.png" &
display "my_plot2.png" &
display "my_plot3.png" &

echo "End"
