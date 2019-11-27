#!/bin/bash
[-e /home/csmajs/bhuan019/assignment-memoryleak/src/main.cpp && echo "main.cpp exists"]
[-f /home/csmajs/bhuan019/assignment-memoryleak/src/command.cpp && echo "command.cpp exists"]
[-d /home/csmajs/bhuan019/assignment-memoryleak/src && echo "src exists"]
([test /home/csmajs/bhuan019/assignment-memoryleak/src/main.cpp] && mkdir new) && echo "new"
[test /home/csmajs/bhuan019/assignment-memoryleak/src/]

exit
