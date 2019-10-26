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

# Diagram
Format: ![Alt Text](https://github.com/cs100/assignment-memoryleak/blob/master/images/download.png)

# Classes
Base Class - The base class will include default constructor Base(){}; and pure virtual function evaluate(); This will act as the main class where the command class and the connector will inherit from.  

Command Class - The command class will include a function that allows various commands to execute. The list of commands will be in the commandNames vector. 

Connector Class - The connector class will include the specific connector's constructor. For example, the AND class will contain the And(Base*, Base*){} constructor along with a function that evaluates the connector's task. 


# Prototype/Research


# Development and Testing Roadmap
