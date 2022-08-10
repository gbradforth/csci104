// MultStatement.cpp:
#include "MultStatement.h"
using namespace std;

MultStatement::MultStatement(std::string variableName, std::string variableName2)
	: m_variableName( variableName ), m_variableName2( variableName2 )
{}


void MultStatement::execute(ProgramState * state, ostream &outf)
{
	int m_value;
	
	//if our second input is a number, convert it to an int
	if (isdigit(m_variableName2[0])) {
	    m_value = stoi(m_variableName2);
	    
	    //if the first input isn't in the map, add it as 0 x val = 0
	    if (!state->inMap(m_variableName))
	        state->insert(m_variableName, 0);
	        
	    //if it is, multiply it's value (from the map) to our value
	    else
	        state->changeVal(m_variableName, state->at(m_variableName) * m_value);
	}
	
	//if our second input is a variable
	else if (state->inMap(m_variableName2) && state->inMap(m_variableName)){
	    //change variable 1's value to variable1 value x variable2 value
	    state->changeVal(m_variableName, state->at(m_variableName) * state->at(m_variableName2));
	}
	//if the first input isn't initialized
	else if (!state->inMap(m_variableName)) {
	    //create a new variable in our map with 0 x variable 2 value = 0
	    state->insert(m_variableName, 0);
	}
	//if the second input isn't initialized
	else if (!state->inMap(m_variableName2)) {
	    //change the value of variable1 to variable1 value x 0 = 0
	    state->changeVal(m_variableName, 0);
	}
	
	state->nextLine(); //move to next line
	
}