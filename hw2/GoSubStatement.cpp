// GoSubStatement.cpp:
#include "GoSubStatement.h"

GoSubStatement::GoSubStatement(int linenum)
{
    this->linenum = linenum;
}


void GoSubStatement::execute(ProgramState * state, std::ostream &outf)
{
    //if the given line number is in the program
    if (state->inRange(linenum)) {
        //add the next line from our current one to the stack
        state->addFront(state->getLine()+1);
        
        //change the line number to the given line number
        state->setLine(linenum);
    }
    
    else {
        //throw error
        outf << "Illegal jump instruction \n";
        //terminate program
        state->setLine(-1);
    }
}
