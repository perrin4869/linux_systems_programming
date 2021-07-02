#!/bin/sh

# Make sure uid is fresh, owned by $USER and does not have set uid flag
./uid
sudo chown root uid
sudo chmod u+s uid
./uid
sudo ./uid
