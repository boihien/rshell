#include <string>
using namespace std;
#include <iostream>
#include <stdio.h>
#include "base.hpp"
#include "command.hpp"
#include "connector.hpp"
#include <string.h>
#include <stdlib.h>

int main(){
    
    while(1){
        cout << "$ ";
        string input;
        getline(cin, input);
        cout << endl;
        if(input == "exit"){
            exit(0);
        }
        Command *c = new Command(input);
        c->evaluate();
        char flag2 = 'e';
        c->filePath(c->argm[2], flag2);
    }
    
    return 0;
}

