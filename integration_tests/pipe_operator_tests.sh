#!/bin/sh

echo "echo hello there" | bin/memoryleak

echo "ls -a" | bin/memoryleak

echo "cat < existingInputFile.txt | tr A-Z a-z | tee newOutputFile1 | tr a-z A-z > newOutputfile2" | bin/memoryleak
