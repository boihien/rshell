#include <iostream>
using namespace std;

Base::Base{

};

void Base::setSuccess(bool& val){
	value = val;
}
bool Base::success(){
	return value;
}
