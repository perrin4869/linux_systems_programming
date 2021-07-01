#!/bin/sh

mkfifo /tmp/demopipe
ls -l /tmp/demopipe
cat /tmp/demopipe &
date > /tmp/demopipe
ps > /tmp/demopipe &
cat /tmp/demopipe
find /tmp -type p
