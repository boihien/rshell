# CS 100 Programming Project

Fall Quarter 2019

Boi-Hien Huang, 862012798

Raajitha Rajkumar, 862015848

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
Format: ![Alt Text](https://github.com/cs100/assignment-memoryleak/blob/master/images/cs100.PNG.png)

# Classes
Base Class - The base class will include default constructor Base(){}; and pure virtual function evaluate(); This will act as the main class where the command class and the connector will inherit from. The evaluate function will be set to 0 in this base class. 

Command Class - The command class will include a function that allows various commands to execute. The list of commands will be in the commandNames vector. The collection in the command class will inherit from the base class. It's child leaf is a exit function where if the user types in the word "exit", the program will close down. The command class will have the "test" and its symbolic equivalent [ ]. It will follow with a flag where
```
-e checks if the file/directory exists
-f checks if the file/directory exists and is a regular file
-d checks if the file/directory exists and is a directory
```
If the test works, it will print out a "(true)" statement and a "(false)" statement if it did not work. 
Additionally, the command class will contain a parenthesis operator that sets a precedence when typing in the command. For example, the command
```
$ (echo A && echo B) || (echo C && echo D)
```
will print
```
A
B
```

Connector Class - The connector class will include the specific connector's constructor. For example, the AND class will contain the And(Base*, Base*){} constructor along with a function that evaluates the connector's task. It will contain private variables like Base* left and Base* right so that the tree can identify what the commands on the left and right of the connector are. The child classes for the connector are the AND, OR, and SemiColon classes. If the user enters && with another command, the second command will execute only if the first one was successfull. If the user enters || along with another command, the second command will execute even if the first one failed. Finally, if the character ';' is typed after a command, the command will always execute. 


# Prototype/Research

**Notes**

Fork() - a function that generates a duplicate of a process by creating two of the same process of the program. Typically, these processes are called "parent" and "child"

execvp() - when this is executed, the file in first argument will load into caller's address space and over-write the program. The second argument will be what the program executes. The program in the first argument will be deleted and replaced by the program in the second argument. This will return negative if it fails. 

waitpid() - a system call that will suspend calling a process unless a *pid* argument in a child class changes its state. 

We researched the various commands for parsing a user input, such as getline() and cin. We decided to use the getline() function since we believe the getline() will produce the least amount of bugs. We also created a test input function that counts the number of elements in a command by counting the spaces. 

Example of fork(): This will return a pid that is different from the parent 
```
int pid;
pid = fork();
```
Example of execvp(): This will replace the address space at the current with the new and execute the command. 
```
char* arg[];
execvp(arg[0], arg);
```
Example of waitpid(): Depending on the value of pid, this function waits for child processes if the value is -1
```
pid_t waitpid(pid_t, int *status, int options);
```
Example of using fork(), execvp(), and waitpid():
```
pid_t pid = fork();

if(pid == 0){
 //failed
}
else if (pid > 0){
 int status;
  waitpid(pid, &status, 0);
}
else{
 execvp(//arguments);
 exit();
}
```


# Development and Testing Roadmap
1. Parsing: First, we need to develop a function to take in input which will be done by Raajitha. She will run tests for it as well to make sure comments are avoided and the exit function works. 

[Parseing Issue](https://github.com/cs100/assigment2-rshell/issues/1)
[Integration Tests Issue](https://github.com/cs100/assigment2-rshell/issues/2)

2. Abstract Base: The base class should be developed in order to develop the other classes. This will be a simple default for evaluate() which will be done by Boi-Hien. He will test to make sure it compiles and connects to the main succesfully.

[Base Class Issue](https://github.com/cs100/assigment2-rshell/issues/3) 

3. Command: This class can be developed next by Boi-Hien in order to see if the commands are executed properly. He will use waitpid(), execvp() and fork(). He will also do integration tests to see if the commands work with the connectors.

[Command Class Issue](https://github.com/cs100/assigment2-rshell/issues/4)
[Command Tests Issue](https://github.com/cs100/assigment2-rshell/issues/5)
 
4. Connector: This class can developed by Raajitha in order to make sure the connectors are being processed. We will need to develop an AND, OR, and SEMI-COLON class under this class to execute each connector. We will also do tests on it to make sure it compiles and interacts properly with the commands. 

[Connector Class Issue](https://github.com/cs100/assigment2-rshell/issues/6)
[Connector Tests Issue](https://github.com/cs100/assigment2-rshell/issues/7) 
