// PrintStatement.cpp:
#include "PrintStatement.h"

PrintStatement::PrintStatement(std::string variableName)
	: m_variableName( variableName )
{}


void PrintStatement::execute(ProgramState * state, std::ostream &outf)
{
    //if the key is in the map 
    if (state->inMap(m_variableName)) { 
        //print the value to outf
        outf << state->at(m_variableName) << "\n"; 
    }
    else {
        //if unused variable, treat as 0, add to map, and print
        state->insert(m_variableName, 0);
        outf << state->at(m_variableName) << "\n"; 
    }
    
    state->nextLine(); //move to next line
}
