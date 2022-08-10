// PrintAllStatement.cpp:
#include "PrintAllStatement.h"

PrintAllStatement::PrintAllStatement()
{}


void PrintAllStatement::execute(ProgramState * state, std::ostream &outf)
{
    //use an iterator to go through the map, print each variable
    for (std::map<std::string, int>::iterator it = state->begin(); it!= state->end(); ++it)
        outf << it->first << " " << it->second << '\n';
    
    state->nextLine(); //move to next line
}
