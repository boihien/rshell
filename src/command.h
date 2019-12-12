#ifndef __COMMAND_H__
#define __COMMAND_H__

#include <iostream>
using namespace std;
#include <string>
#include "base.h"

class Command: public Base{
    private:
        string in;
    public:
        Command(string input);
        char * parse(string input);
        void evaluate();
	string comm;
	char* argm[1024];
	bool filePath(const char* path, char flag);
};
class Pipe: public Base{
	protected:
		string l;
		string r;
		char* argmL[1024];
		char* argmR[1024];
	public:
		Pipe();
		Pipe(string left, string right);
		void evaluate();
};

class Redirect: public Base{
	protected:
		string l;
		string r;
		char* argmL[1024];
		char* argmR[1024];
	public:
		Redirect();
		Redirect(string left, string right);
		void evaluate();
};

#endif
