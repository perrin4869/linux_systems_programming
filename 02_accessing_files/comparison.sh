#!/bin/sh

time ./rawio 1 10000000
time ./bufio 1 10000000
time ./rawio 100 100000
time ./bufio 100 100000
