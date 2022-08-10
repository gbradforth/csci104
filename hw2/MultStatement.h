#ifndef MULT_STATEMENT_INCLUDED
#define MULT_STATEMENT_INCLUDED

#include "Statement.h"
#include "ProgramState.h"

class MultStatement: public Statement
{
private:
	std::string m_variableName;
	std::string m_variableName2;

public:
	MultStatement(std::string variableName, std::string variableName2);
	
	virtual void execute(ProgramState * state, std::ostream &outf);
};

#endif
