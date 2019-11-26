#ifndef __BASE_H__
#define __BASE_H__
#include <iostream>
using namespace std;
#include <vector>
#include <string>

class Base{
	private:
		bool value;
	public:
		Base(){};
		virtual void evaluate() = 0;
		void setSuccess(bool& val);
		bool success();
};

#endif
