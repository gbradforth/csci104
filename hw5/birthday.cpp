#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <stdlib.h> 

#include "Hashtable.h"
using namespace std;
/**
Confirm the Birthday Paradox: With an initial size of 365, add items until the first probe
 occurs or (very unlikely) you resize the array. Run this a bunch of times (at least 1000).
  You should find that approximately 50.7% of the time you insert 23 things or less, and 
  the rest of the time you insert 24 things or more.
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
    int c;
    double t3 = 0, t4 = 0;
	int n = 1000;
	for (int i = 0; i < 1000; i++)
	{
	    Hashtable<int> hashtable(false, 365);
	    c = 0;
        int probe = 0;
	    while (probe == 0)
	    {
	        string s = generateRandomString();
            probe = hashtable.add(s, rand() % n);
            c++;
	    }
	    if (c >= 24) t4++;
        else t3++;
	}
	
	cout << "Twenty three or less: " << t3/10 << "%" << endl;
    cout << "Twenty four or more: " << t4/10 << "%" << endl;
}

