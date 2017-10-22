#!/bin/bash

find $1 -type d | wc -l > dirs 
find $1 -type f | wc -l > files
read dirs < dirs
read files < files
rm dirs;
rm files;
echo "processed all the files from $1"
echo "There were $dirs directories."
echo "there were $files regular files."
