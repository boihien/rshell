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
	Command *arg = new Command(input);
        arg->evaluate();
        
        
    }
    
    return 0;
}
