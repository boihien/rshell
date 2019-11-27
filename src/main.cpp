#include <string>
using namespace std;
#include <iostream>
#include <stdio.h>
#include "base.h"
#include "command.h"
#include <string.h>
#include <stdlib.h>

int main(){
    
    while(1){
        cout << "$ ";
	string input;
        getline(cin, input);
        if(input == "exit"){
            exit(0);
        }
	Command *c = new Command(input);
        c->evaluate();
	if(input == "test"){
		char flag2 = 'e';
		c->filePath(c->argm[2], flag2);
	}
        
    }
    
    return 0;
}
