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
#include <sys/stat.h>
#include <fcntl.h>
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
    //cout << "command is: ";
    int w = 0;
    while (token != NULL){
        cout << token << " ";
        command[w] = token;
        token = strtok(NULL, " ");
        w++;
    }
    /*cout << endl;
    cout << "command array contains: " << endl;
    for(int y = 0; y < w; y++){
        cout << "[" << y << "]" << " " << command[y] << endl;
    }
    cout << endl;*/
    
    int status;
    pid_t pid = -1;
    pid = fork();
    if(pid == 0){
        comm = command[0];
        execvp(command[0], command);
	int errorC = errno;
    	cout << comm << ":command is invalid" << endl;
    	exit(errorC);
    	exit(EXIT_SUCCESS);
    }
    else if(pid > 0){
	if((pid = wait(&status)) == -1){
		perror("wait error");
	}
	else{
		//worked
		if((WIFEXITED(status)) && (WEXITSTATUS(status) == 0)){
			success = true;
		}
		else{
			success = false;
		} 
	}
    }
    else{
	perror("fork failed");
	cout << "Fork() did not run" << endl;
	exit(EXIT_FAILURE);
    }
return;  
}

bool Command::filePath(const char* path, char flg){
	struct stat m;//creates stat m, pathname, and flag
	const char* pathname = path;
	char flag = flg;
	
	stat(pathname, &m);//stats the file that is pointed to, fills buff
	string t = "true";
	string f = "false";
	//check if the file/dir exists
	if(flag == 'e'){
		//S_ISREG = is it a regular fle
		//S_ISDIR = directory?
		//using st_mode field 
		if(S_ISREG(m.st_mode) || S_ISDIR(m.st_mode)){
			cout << "(True)" << endl;
			return true;
		}
		else{
			cout << "(False)" << endl;
			return false;
		}
	}
	//check if the file/dir exists and is a regular file
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
	//check id the file/dir exists and is a dir
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

Pipe::Pipe():Base(){}

Pipe::Pipe(string left, string right){
	l = left;
	r = right;
}

void Pipe::evaluate(){
	int pipefd[2];
	pipe(pipefd);
	int saveStdin;
	int saveStdout;

	int pid = -1;
	pid = fork();
	int returnStat;
	//cout << "reached if";
	if(pid == 0){
		cout << "reached pid" << endl;
		saveStdout = dup(1);
		dup2(pipefd[1], 1);
		close(pipefd[0]);
		
		dup2(saveStdout, 1);
		int errCode = errno;
		exit(errCode);
		exit(EXIT_SUCCESS);		
	}
	else if(pid > 0){
		if((pid= wait(&returnStat)) == -1){
			perror("error");
		}
		else{
			if((WIFEXITED(returnStat)) && WEXITSTATUS(returnStat) == 0){
				saveStdin = dup(0);
				dup2(pipefd[0], 0);
				close(pipefd[1]);
			
				dup2(saveStdin, 0);
			}
			else{
				perror("failed");
			}
		}
	
	}
	else{
		perror("failed fork");
		cout << "failed fork" << endl;
		exit(EXIT_FAILURE);
	}
}
Redirect::Redirect():Base(){}

Redirect::Redirect(string left, string right){
	l = left;
	r = right;
}

void Redirect::evaluate(){
	int pid = -1;
	int w = r.length();
	char* str = new char[w + 1];
	int saveStd;
	strcpy(str, r.c_str());
	pid = fork();
	int returnStat;
	if(pid == 0){
		saveStd = dup(1);
	}
}
#endif
