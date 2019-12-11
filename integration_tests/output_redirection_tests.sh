#!/bin/sh

echo "echo X && echo Y || echo Z && echo S >> outputfile1.txt" | bin/memoryleak

echo "(echo X && echo Y) || (echo Z && echo S) >> outputfile1.txt" | bin/memoryleak

echo "ls -a; echo hello there && mkdir nTest >> outputfile1.txt" | bin/memoryleak
