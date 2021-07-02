#!/bin/sh

# Make sure transfer can change ownership
sudo chown root transfer
sudo chmod u+s transfer

# Requires users chris, jane and mary to be present in the system
sudo chown chris testdir/apple
sudo chown jane testdir/banana
sudo chown chris testdir/orange

./transfer chris mary testdir
ls -l testdir
