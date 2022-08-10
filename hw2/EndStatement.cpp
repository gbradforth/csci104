// EndStatement.cpp:
#include "EndStatement.h"

EndStatement::EndStatement()
{}


void EndStatement::execute(ProgramState * state, std::ostream &outf)
{
    //terminate program by setting line number to -1,
    //which will break out of the loop in interpreter
    state->setLine(-1);
}
