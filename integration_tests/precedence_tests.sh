#!/bin/bash
(echo A && echo B) || (echo C && echo D)
echo A && (echo B || echo C) && echo D
echo hello || (echo there || echo kenobi)
(echo hello || echo there) || echo kenobi
mkdir general || (ls && echo kenobi)
mkdir grevious && (mkdir count && (mkdir dooku))
ls; mkdir jedi && (test -e /home/csmajs/bhuan019/assignment-memoryleak/src/main.cpp && echo exec)

exit 
