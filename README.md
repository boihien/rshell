# CS 100 Programming Project

Fall Quarter 2019

Boi-Hien Huang, 862012798

Joshua Ortega, 862062659

# Introduction
The goal of our project is to develop a command shell that
1. prints a command prompt **$**
2. reads in any line of command
3. executes the command using **fork**, **execvp**, and **waitpid**. 

The commands can be seperated by ```&&```, ```||```, and ```;``` where the command executes only if
```
&& - the first one was successful
|| - the first one failed
; - is always executed 
```
We will be using the composite pattern where there is a base class, a composite class, and a leaf class. The composite class will consist of the various commands and the leaf class will contain the characters that connect the commands together. 

# Diagram
Composite Pattern
Format: ![Alt Text](https://github.com/cs100/assignment-memoryleak/blob/master/images/CS100.PNG)

# Classes
Base Class - The base class will include default constructor Base(){}; and pure virtual function evaluate(); This will act as the main class where the command class and the connector will inherit from. The evaluate function will be set to 0 in this base class. 

Command Class - The command class will include a function that allows various commands to execute. The list of commands will be in the commandNames vector. The collection in the command class will inherit from the base class. It's child leaf is a exit function where if the user types in the word "exit", the program will close down.

Connector Class - The connector class will include the specific connector's constructor. For example, the AND class will contain the And(Base*, Base*){} constructor along with a function that evaluates the connector's task. It will contain private variables like Base* left and Base* right so that the tree can identify what the commands on the left and right of the connector are. The child classes for the connector are the AND, OR, and SemiColon classes. If the user enters && with another command, the second command will execute only if the first one was successfull. If the user enters || along with another command, the second command will execute even if the first one failed. Finally, if the character ';' is typed after a command, the command will always execute. 


# Prototype/Research

**Notes**

Fork() - a function that generates a duplicate of a process by creating two of the same process of the program. Typically, these processes are called "parent" and "child"

execvp() - when this is executed, the file in first argument will load into caller's address space and over-write the program. The second argument will be what the program executes. The program in the first argument will be deleted and replaced by the program in the second argument. This will return negative if it fails. 

waitpid() - a system call that will suspend calling a process unless a *pid* argument in a child class changes its state. 

We researched the various commands for parsing a user input, such as getline() and cin. We decided to use the getline() function since we believe the getline() will produce the least amount of bugs. We also created a test input function that counts the number of elements in a command by counting the spaces. 


# Development and Testing Roadmap
1. Abstract Base
2. Commands
3. Connectors
4. AND(&&), OR(||), ;
