#ifndef GOTO_STATEMENT_INCLUDED
#define GOTO_STATEMENT_INCLUDED

#include "Statement.h"
#include <iostream>

class GoToStatement: public Statement
{
private:
	int linenum;
	
public:
	GoToStatement(int linenum);
	virtual void execute(ProgramState * state, std::ostream &outf);
};

#endif
