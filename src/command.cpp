#ifndef __COMMAND_CPP__
#define __COMMAND_CPP__
#include "command.h"
#include "base.h"
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Command::Command(string input){
	in = input;
}

char * Command::parse(string input){
    char *inputchar = new char[64];
    int i = 0;
    if(input == "exit"){
        exit(1);
    }
    if(input.at(0) == '"'){
        int x = 0;
        for(int j = 1; j < input.size() - 1; j++){
            inputchar[x] = input.at(j);
            x++;
        }
    }else{
        for(i = 0; i < input.size(); i++){
            if(input.at(i) == ';'){
                
                break;
            }
            if(input.at(i) == '|' && input.at(i+1) == '|'){
                
                break;
            }
            if(input.at(i) == '&' && input.at(i+1) == '&'){
                
                break;
            }
            if(input.at(i) == '#'){
                break;
            }
            inputchar[i] = input.at(i);
        }
    }
    return inputchar;
}

void Command::evaluate(){
    bool success;
    char *command[64];
    string input = in;
    if(input == "exit"){
        exit(1);
    }
    char *inputarr = parse(input);
    char *token = strtok(inputarr, " ");
    cout << "command is: ";
    int w = 0;
    while (token != NULL){
        cout << token << " ";
        command[w] = token;
        token = strtok(NULL, " ");
        w++;
    }
    cout << endl;
    cout << "command array contains: " << endl;
    for(int y = 0; y < w; y++){
        cout << "[" << y << "]" << " " << command[y] << endl;
    }
    cout << endl;
    
    pid_t pid = -1;
    pid = fork();
    if(pid == 0){
        comm = command[0];
        if(execvp(command[0], command) == -1){
            perror("execvp failed");
            cout << "false" << endl;
            success = false;
            return;        
        }
    }
    else if (pid < 0){
        perror("fork failed");
        cout << "false" << endl;
     
        success = false;
        return;
        
    }
    else{
	int status;
       if(waitpid(pid, &status, 0) == -1){
            perror("wait failed");
           cout << "false" << endl;
           exit(0);
           return;
            
        }
    }

    success = true;
    cout << "true" << endl;
    return;  
}
#endif
