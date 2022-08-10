#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <stdlib.h> 

#include "Hashtable.h"
using namespace std;
/**
Probe Rate: How many probes occur, on average, when inserting n elements into the Hashtable?
When the Hashtable is (almost) half full, you should expect 1 probe on average. 
When the Hashtable is about a quarter full, you should expect 1/3 probes on average. 
Since your Hashtable oscillates between these loading factors when resizing, 
you should probably find something a bit smaller than 2n/3.
**/

std::string generateRandomString()
{
    std::string s = "";
    for (int i = 0; i < 28; i++)
    {
        s += (char)(( (rand()+1) % 26) + 97);
    }
    return s;
}


int main()
{
	srand(time(NULL));
	double probes = 0;
	int n = 100;
	
	for (int i = 0; i < 1000; i++)
	{
	    Hashtable<int> table(false,1000);
	    for (int j = 0; j < n; j++)
	    {
	        std::string s = generateRandomString();
	        
	        probes += table.add(s,rand() % n);
	    }
	}
	
	cout << "Actual: " << probes/n << endl;
	cout << "Expecting: " << (2*n)/3 << endl;
	cout << "Difference: " << (((2*n)/3) - probes/n) << endl;

}
