// LetStatement.cpp:
#include "LetStatement.h"
using namespace std;

LetStatement::LetStatement(std::string variableName, int value)
	: m_variableName( variableName ), m_value( value )
{}


// The LetStatement version of execute() should make two changes to the
// state of the program:
//
//    * set the value of the appropriate variable
//    * increment the program counter
void LetStatement::execute(ProgramState * state, ostream &outf)
{
	//if there's not a variable with that name in our map
	if (!state->inMap(m_variableName))
	    state->insert(m_variableName, m_value); //add this variable to our map
	else 
	    state->changeVal(m_variableName, m_value); //change the value of the key variableName
	
	state->nextLine(); //move to next line
}
