#ifndef _CONNECTOR_H__
#define _CONNECTOR_H__
#include <string>
#include "base.h"

class AND: public Base{
	private:
		string left;
		string right;
	public:
		AND();
		AND(string first, string second);
		void evaluate();	
};

class OR: public Base{
	private:
		string left; 
		string right;
	public:
		OR();
		OR(string first, string second);
		void evaluate();
};

class SEMICOLON: public Base{
	private:
		string left;
		string right;
	public:
		SEMICOLON();
		SEMICOLON(string first, string second);
		void evaluate();
};

#endif
