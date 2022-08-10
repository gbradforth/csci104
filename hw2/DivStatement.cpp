// DivStatement.cpp:
#include "DivStatement.h"
using namespace std;

DivStatement::DivStatement(std::string variableName, std::string variableName2)
	: m_variableName( variableName ), m_variableName2( variableName2 )
{}


void DivStatement::execute(ProgramState * state, ostream &outf)
{
	int m_value;

    //if our second input is a number, convert it to an int
	if (isdigit(m_variableName2[0])) {
	    m_value = stoi(m_variableName2);
	    
	    //if the value we're dividing by is 0, then end the program and error message
	    if (m_value == 0) {
	        outf << "Divide by zero exception \n";
	        state->setLine(-1);
	    }
	
	    //if the first input isn't in the map, add it as 0 / val = 0
	    else if (!state->inMap(m_variableName))
	        state->insert(m_variableName, 0);
	    //if it is, divide it's value (from the map) to our value
	    else
	        state->changeVal(m_variableName, state->at(m_variableName) / m_value);
	}
	
	//if our second input is a variable
	else if (state->inMap(m_variableName2) && state->inMap(m_variableName)){
	
	    //if the variable's value is 0, end the program and error message
	    if (state->at(m_variableName2) == 0) {
	        outf << "Divide by zero exception \n";
	        state->setLine(-1);
	    }
	    //change variable 1's value to variable1 value / variable2 value
	    else
	        state->changeVal(m_variableName, state->at(m_variableName) / state->at(m_variableName2));
	}
	
	//if the second input isn't initialized, it's value is zero
	//this will end the program and print an exception
	else if (!state->inMap(m_variableName2)) {
	    outf << "Divide by zero exception \n";
	    state->setLine(-1);
	}
	//if only the input hasn't been initialized
	else if (!state->inMap(m_variableName)) {
	    //create a new variable in the map with value 0 / variable2 value = 0
	    state->insert(m_variableName, 0);
	}
	
	state->nextLine(); //move to next line
	
}