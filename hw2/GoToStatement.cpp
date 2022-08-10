// GoToStatement.cpp:
#include "GoToStatement.h"

GoToStatement::GoToStatement(int linenum)
{
    this->linenum = linenum;
}


void GoToStatement::execute(ProgramState * state, std::ostream &outf)
{
    //if the given line number is in the program
    if (state->inRange(linenum)) {
        //change line number to the given line number
        state->setLine(linenum);
    }
    
    else {
        //throw error
        outf << "Illegal jump instruction \n";
        //terminate program
        state->setLine(-1);
    }
}
