// ReturnStatement.cpp:
#include "ReturnStatement.h"

ReturnStatement::ReturnStatement()
{}


void ReturnStatement::execute(ProgramState * state, std::ostream &outf)
{
    //if the stack isn't empty
    if (state->getLength() != 0)
        //change the line number to the one from the most recent GOSUB
        state->setLine(state->popFront());
    else {
        //terminate program
        state->setLine(-1); 
    }
        
}
