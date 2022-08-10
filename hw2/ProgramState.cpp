// ProgramState.cpp:
#include "ProgramState.h"

ProgramState::ProgramState(int numLines)
{
    m_numLines = numLines;
    lineNum = 1;
    sub = std::stack<int>();
    vars = std::map<std::string, int>();
}

//stack functions

//pushes a to the stack
void ProgramState::addFront(int a) 
{
    sub.push(a);
}
//deletes the top of the stack and returns it
int ProgramState::popFront()
{
    int temp = sub.top();
    sub.pop();
    return temp;
}

//returns the length of the stack
int ProgramState::getLength() {return sub.size();}



//map functions

//inserts a new element to the map
void ProgramState::insert(std::string variable, int value)
{
    vars.insert(std::pair<std::string,int>(variable,value));
}

//returns the value of the variable in the map
int ProgramState::at(std::string variable)
{
    return (vars.at(variable));
}

//changes the value of the variable to a new value
void ProgramState::changeVal(std::string variable, int value)
{
    vars.find(variable)->second = value;
}

//returns an iterator to the beginning of the map
std::map<std::string, int>::iterator ProgramState::begin() {return vars.begin();}

//returns an iterator to the end of the map
std::map<std::string, int>::iterator ProgramState::end() {return vars.end();}

//returns whether a variable is in the map
bool ProgramState::inMap(std::string variable) {return vars.count(variable);}

//line functions

//increments line number by one
void ProgramState::nextLine() {lineNum++;}

//changes line number to linenum
void ProgramState::setLine(int linenum) {lineNum = linenum;}

//returns whether linenum is in range of the program
bool ProgramState::inRange(int linenum) {return linenum <= m_numLines && linenum > 0;}

//returns the current line number
int ProgramState::getLine() {return lineNum;}



