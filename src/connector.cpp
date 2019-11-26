#include <iostream>
using namespace std;
#include "main.cpp"
#include "connector.h"

AND::AND(){
}

AND::AND(string first, string second){
	left = first;
	right = second;
}
void AND::evaluate(){
			
	parse(left);//tests left string

	if(success()){//left string worked
		Command* c = new Command(right);//evaluate right side
		right->evaluate();
	}
}

OR::OR(){

}
OR::OR(string first, string second){
	left = first;
	right = second;
}
void OR::evaluate(){

}

SEMICOLON::SEMICOLON(){

}
SEMICOLON::SEMICOLON(string first, string second){
	left = first;
	right = second;
}
void SEMICOLON::evaluate(){
	
}

