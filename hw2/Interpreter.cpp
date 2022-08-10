// Interpreter.cpp
#include "Statement.h"
#include "LetStatement.h"
#include "PrintStatement.h"
#include "ReturnStatement.h"
#include "GoSubStatement.h"
#include "EndStatement.h"
#include "PrintAllStatement.h"
#include "GoToStatement.h"
#include "AddStatement.h"
#include "SubStatement.h"
#include "MultStatement.h"
#include "DivStatement.h"
#include "IfStatement.h"
#include <vector>
#include <string>
#include <sstream> 
#include <fstream>
#include <cstdlib>


using namespace std;

// parseProgram() takes a filename as a parameter, opens and reads the
// contents of the file, and returns an vector of pointers to Statement.
void parseProgram(istream& inf, vector<Statement *> & program);

// parseLine() takes a line from the input file and returns a Statement
// pointer of the appropriate type.  This will be a handy method to call
// within your parseProgram() method.
Statement * parseLine(string line);

// interpretProgram() reads a program from the given input stream
// and interprets it, writing any output to the given output stream.
// Note:  you are required to implement this function!
void interpretProgram(istream& inf, ostream& outf);


int main()
{
        cout << "Enter BASIC program file name: ";
        string filename;
        getline(cin, filename);
        ifstream infile(filename.c_str());
        if (!infile)
        {
                cout << "Cannot open " << filename << "!" << endl;
                return 1;
        }
        interpretProgram(infile, cout);
}



void parseProgram(istream &inf, vector<Statement *> & program)
{
	program.push_back(NULL);
	
	string line;
	while( ! inf.eof() )
	{
		getline(inf, line);
		if (line != "") //if statement to prevent errors when extra newline
		    program.push_back( parseLine( line ) );
	}
}


Statement * parseLine(string line)
{
	Statement* statement;	
	stringstream ss;
	string type;
	string var;
	int val;
	
	//extra variables added for additonal functionality
	string var2;
	string var3;
	int val2;

	ss << line;
	ss >> type; 
	ss >> type; //extra type input added to get rid of line number
	
	if ( type == "LET" )
	{
		ss >> var;
		ss >> val;

		statement = new LetStatement(var, val);
	}

	if ( type == "PRINT")
	{
	    ss >> var;
	    
	    statement = new PrintStatement(var);
	}
	
	if ( type == "PRINTALL")
	{
	    statement = new PrintAllStatement();
	}
	
	if (type == "ADD")
	{
	    ss >> var;
	    //take in the second input as a string, will be handled in AddStatement
	    ss >> var2; 
	    
	    statement = new AddStatement(var,var2);
	}
	
	if (type == "SUB")
	{  
	    ss >> var;
	    ss >> var2;
	    
	    statement = new SubStatement(var, var2);
	}
	
	if (type == "MULT")
	{
	    ss >> var;
	    ss >> var2;
	    
	    statement = new MultStatement(var, var2);
	}
	
	if (type == "DIV")
	{
	    ss >> var;
	    ss >> var2;
	    
	    statement = new DivStatement(var, var2);
	}
    
    if (type == "GOTO")
	{
	    ss >> val;
	    
	    statement = new GoToStatement(val);
	}
	
	if (type == "IF")
	{
	    ss >> var; //variable 
	    ss >> var2; //operator
	    ss >> val; //integer
	    ss >> var3; //THEN
	    ss >> val2; //line number
	    
	    statement = new IfStatement(var,var2,val,val2);
	}
	
	if (type == "GOSUB")
	{
	    ss >> val;
	    
	    statement = new GoSubStatement(val);
	}
	
	if (type == "RETURN")
	{
	    statement = new ReturnStatement();
	}
    
    if (type == "END" || type == ".")
	{
	    statement = new EndStatement();
	}
		
	return statement;
}


void interpretProgram(istream& inf, ostream& outf)
{
	vector<Statement *> program;
	parseProgram( inf, program );
	
	//programstate for all statements
	ProgramState* ps = new ProgramState(program.size());
    
    //goes through program with our lineNumber from ps
    //when it is set to -1, the program will terminate
	while (ps->getLine() != -1) { 
	    //execute each line in program
	    program.at(ps->getLine())->execute(ps, outf); 
	
	}
	
	//delete allocation
	for (unsigned int i = 0; i < program.size(); i++)
	{
	    delete program[i];
	}
	delete ps;
}
