#!/bin/sh

./strftime
export TZ=:EST
./strftime
# Available locales:
# locale -a
export LC_ALL=de_DE.utf8
./strftime
export TZ=:CET # German locale
./strftime
