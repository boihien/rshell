#!/bin/bash
test -e /home/csmajs/bhuan019/assignment-memoryleak/src/main.cpp && echo "main.cpp exists"
test -f /home/csmajs/bhuan019/assignment-memoryleak/src/command.cpp && echo "command.cpp exists"
test -d /home/csmajs/bhuan019/assignment-memoryleak/src && echo "src exists"
test /home/csmajs/bhuan019/assignment-memoryleak/src/ && echo "src is there"
(test -e /home/csmajs/bhuan019/assignment-memoryleak/src/main.cpp) && (mkdir hello && echo "finish")


exit

