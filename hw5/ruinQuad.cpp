#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <stdlib.h> 

#include "Hashtable.h"
using namespace std;
/**
Ruin Quadratic Probing: Start with an intial Hashtable size that is non-prime, and find a 
sequence of inputs that causes your program to hang (or trigger a failsafe if you programmed
one in). It may be easier to randomly generate a lot of test cases and run them until something
fails than to systematically try and find a test case by hand. You should be able to do this
for a Hashtable size of 12 or larger.
**/

std::string generateRandomString()
{
    std::string s = "";
    for (int i = 0; i < 28; i++)
    {
        s += (char)(( (rand()+1) % 28) + 97);
    }
    return s;
}


int main()
{
	srand(time(NULL));
	int n = 1000;
	for (int i = 0; i < 10; i++)
	{
	    Hashtable<int> table(false,22);
	    for (int j = 0; j < n; j++)
	    {
	        std::string s = generateRandomString();
	        table.add(s,rand() % n);
	        
	    }
	}

}
