// AddStatement.cpp:
#include "AddStatement.h"
using namespace std;

AddStatement::AddStatement(std::string variableName, std::string variableName2)
	: m_variableName( variableName ), m_variableName2( variableName2 )
{}


void AddStatement::execute(ProgramState * state, ostream &outf)
{
	int m_value;
	
	//if our second input is a number, convert it to an int
	if (isdigit(m_variableName2[0])) {
	    m_value = stoi(m_variableName2);
	    
	    //if the first input isn't in the map, add it as 0 + val
	    if (!state->inMap(m_variableName)) 
	        state->insert(m_variableName, m_value);
	        
	    //if it is, add it's value (from the map) to our value
	    else
	        state->changeVal(m_variableName, state->at(m_variableName) + m_value);
	}
	
	//if our second input is a variable
	else if (state->inMap(m_variableName2) && state->inMap(m_variableName)){
	
	    //change variable 1's value to variable1 value + variable2 value
	    state->changeVal(m_variableName, state->at(m_variableName) + state->at(m_variableName2));
	}
	
	//if both inputs have not been initialized
	else if (!state->inMap(m_variableName) && !state->inMap(m_variableName2)) {
	    //create a new variable in the map with value 0
	    state->insert(m_variableName, 0);
	}
	//if only the first input hasn't been initialized
	else if (!state->inMap(m_variableName)) {
	    //create a new variable in the map with value 0 + variable2 value
	    state->insert(m_variableName, state->at(m_variableName2));
	}
	
	state->nextLine(); //move to next line
	
}