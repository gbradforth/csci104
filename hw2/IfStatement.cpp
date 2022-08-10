// IfStatement.cpp:
#include "IfStatement.h"

IfStatement::IfStatement(std::string variableName, std::string op, int value, int linenum)
{
    m_variableName = variableName;
    this->op = op;
    m_value = value;
    m_linenum = linenum;
}


void IfStatement::execute(ProgramState * state, std::ostream &outf)
{
    //if the line number given is out of range
    if (!state->inRange(m_linenum)) {
        //throw error
        outf << "Illegal jump instruction \n";
        //end the program
        state->setLine(-1);
    }
    //the operator is < and the IF statement is true
    else if (op == "<" && state->at(m_variableName) < m_value)
        //go to the line number specified in the THEN statement
        state->setLine(m_linenum);
    //same logic for the rest
    else if (op == "<=" && state->at(m_variableName) <= m_value)
        state->setLine(m_linenum);
    else if (op == ">" && state->at(m_variableName) > m_value)
        state->setLine(m_linenum); 
    else if (op == ">=" && state->at(m_variableName) >= m_value)
        state->setLine(m_linenum);
    else if (op == "=" && state->at(m_variableName) == m_value)
        state->setLine(m_linenum);
    else if (op == "<>" && state->at(m_variableName) != m_value)
        state->setLine(m_linenum);
        
    //if the IF statement is not true, just move on
    else
        state->nextLine();
}
