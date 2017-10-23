#!/usr/bin/bash

Directory=$1
cd $Directory
files=$(find . -type f|wc -l)
dirs=$(find . -type d|wc -l)
echo "There were $dirs directories."
echo "There were $files regular files."
