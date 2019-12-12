#ifndef __COMMAND_HPP_
#define __COMMAND_HPP_

#include <iostream>
using namespace std;
#include <string.h>
#include "base.hpp"
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

class Command: public Base{
    private:
        string in;
    public:
        char* argm[1024];
        Command(string input){
            in = input;
        }
        virtual char * parse(string input){
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
        virtual void evaluate(){
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
            command[w] = nullptr;
            cout << endl;
            cout << endl;
            pid_t pid;
            int status;

            if((pid = fork()) < 0){
                cout << "forking failed" << endl;
                exit(0);
            }
            if(pid == 0){
                if(execvp(command[0], command) < 0){
                    perror("execvp of ls failed");
                    exit(1);
                }
            }else{
                while (wait(&status) != pid);
            }
            return;
        }
        
        bool filePath(const char* path, char flg){
            struct stat m;
            const char* pathname = path;
            char flag = flg;
            
            stat(pathname, &m);
            string t = "true";
            string f = "false";
    
            if(flag == 'e'){
              
                if(S_ISREG(m.st_mode) || S_ISDIR(m.st_mode)){
                    cout << "(True)" << endl;
                    return true;
                }
                else{
                    cout << "(False)" << endl;
                    return false;
                }
            }
            
            else if(flag =='f'){
                if(S_ISREG(m.st_mode) || S_ISDIR(m.st_mode)){
                    if(S_ISREG(m.st_mode)){
                        cout << "(True)" << endl;
                        return true;
                    }
                    else{
                        cout << "(False)" << endl;
                        return false;
                    }
                }
                else{
                    cout << "(False)" << endl;
                    return false;
                }
            }
            
            else if(flag == 'd'){
                if(S_ISREG(m.st_mode) || S_ISDIR(m.st_mode)){
                    if(S_ISDIR(m.st_mode)){
                        cout << "(True)" << endl;
                        return true;
                    }
                    else{
                        cout << "(False)" << endl;
                        return false;
                    }
                }
                else{
                    cout << "(False)" << endl;
                    return false;
                }
            }
            else{
                cout << "use -e functionaliy" << endl;
                return false;
            }
        }
};

#endif
