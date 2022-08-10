#include <stdlib.h>
#include <vector>
#include <utility> 
#include <string>
#include <iostream>
#include <math.h> 


template<class T>
  class Hashtable {
     public:
       Hashtable(bool debug = false, unsigned int size = 11);
       /*
       Constructor for the Hashtable, initially allocating size elements to the array. 
       The effect of the Boolean debug flag is described below.
       */

       ~Hashtable ();
       //Destructor
       
       int add(std::string k, const T& val);
       /*
       If k is already in the Hashtable, then do nothing.
       If it is new, add it to the Hashtable with the specified value.
       Returns the number of probes required to place k (if no probes are required, return 0).
       */
       
       const T& lookup(std::string k);
       /*
       Returns the value associated with k. Don’t crash if k is not in the Hashtable, 
       but you can return whatever T value you like (possibly something else in the Hashtable, or a garbage value).
       */
       
       void reportAll(std::ostream &) const;
       /*
       output, to the given stream, every (key,value) pair, in the order they appear in the Hashtable;
        on each line, output the key, followed by a space, followed by the value, and then a newline.
        Note that this requires the T type to have operator« defined.
       */
        
        bool resized;
        //public so it can be used in birthday.cpp
   private:
   
       void resize();
       /*
        A private helper function which approximately doubles the number of indices available.
        You call this function when an insert would increase the load factor above 0.5.
       */
       
       int hash(std::string k) const;
       /*
       This private/protected function takes a string as input, and outputs a pseudo-random
       index to store it at.
       */
       
       std::pair<std::string,T>** table;
       /* our hash table, stored in a dynamic array of pairs of strings and Ts */
       
       long long r1,r2,r3,r4,r5;
       /* our random numbers */
       
       unsigned int m;
       /* size variable: the total size of the hash table */
       
       double n;
       /* amount of objects that have been inserted into the hash table */
       
       T garbage{};
       /* garbage T value */

  };
  


template<class T>
Hashtable<T>::Hashtable(bool debug, unsigned int size)
{
    m = size;
    n = 0;
    resized = false;
    
    //create and set our hash table to nullptrs
    table = new std::pair<std::string,T> * [m];
    for (int i = 0; i < m; i++) {
        table[i] = NULL;
    }
    
    //set random numbers
    if (debug == 0) {
        r1 = rand() % m;
        r2 = rand() % m;
        r3 = rand() % m;
        r4 = rand() % m;
        r5 = rand() % m;
    }
    else {
        r1=983132572;
        r2=1468777056;
        r3=552714139;
        r4=984953261;
        r5=261934300;
    }
    
}


template<class T>
Hashtable<T>::~Hashtable() 
{
    for (int i = 0; i < m; i++) {
        if (table[i] != NULL){
            delete table[i];
        }
    }
    delete[] table;
}

template<class T>
int Hashtable<T>::add(std::string k, const T& val)
{
    int probes_required = 0;
    
    //if this addition will put the load factor over 0.5, resize it
    if ((n+1) / double(m) >= 0.5)
    {
        resize();
        resized = true;
    }
    
    //hash our string
    int h = hash(k);
    
    //loop through the array until we find an untaken and unique node to place our item
    while (table[h] != NULL && table[h]->first != k) {
        probes_required++;
        h = (h + probes_required*probes_required) % m; //quadratic probing formula
        
    }
    
    //add our item to the index found from our hashing and probing
    table[h] = new std::pair<std::string,T>(k, val);
    n++;
    
    return probes_required;
}

template<class T>
const T& Hashtable<T>::lookup(std::string k)
{
    //required for our quadratic probing
    int quad_probe = 0;
    //hash our string
    int h = hash(k);
    
    //loop through the array we find the node or a null node (meaning there's no other items left)
    while (table[h] != NULL && table[h]->first != k) {
        quad_probe++;
        h = h + (quad_probe*quad_probe)% m; 
    }
    
    //if not in hashtable
    if (table[h] == NULL)
        return garbage;
    else //return the value of the item that we found
        return table[h]->second;
}

template<class T>
void Hashtable<T>::reportAll(std::ostream & ofile) const
{
    for (int i = 0; i < m; i++) {
        if (table[i] != NULL)
            ofile << i << " " << table[i]->first << " " << table[i]->second << "\n";
    }
}

template<class T>
void Hashtable<T>::resize()
{
    int sizes[17] = {11, 23, 47, 97, 197, 397, 797, 1597, 3203, 6421, 12853, 25717, 51437, 102877, 205759, 411527, 823117};
    int newM;
    
    //set new size to either the next one in this list or the next largest one that it's closest to
    for (int i = 0; i < 17; i++)
    {
        if (m == sizes[i])
            newM = sizes[i+1];
        else {
            if(m > sizes[i] && m < sizes[i+1])
            {
                newM = sizes[i+1];
            }
        }
    }
    
    //create a copy of the table
    std::pair<std::string,T>** oldTable = table;
    
    //wipe our table and recreate it with the larger size
    table = new std::pair<std::string,T> * [newM];
    for (int i = 0; i < newM; i++) {
        table[i] = NULL;
    }
    n = 0;
    
    //redo our random numbers
    r1 = rand() % m;
    r2 = rand() % m;
    r3 = rand() % m;
    r4 = rand() % m;
    r5 = rand() % m;
    
    int old_m = m;
    m = newM;
    
    //add our values from oldTable into the new bigger table
    for (int i = 0; i < old_m; i++)
    {
        if (oldTable[i] != NULL){
            add(oldTable[i]->first,oldTable[i]->second);
        }
    }
}

template<class T>
int Hashtable<T>::hash(std::string k) const
{
    long long w[5] = {0, 0, 0, 0, 0};
    int w_count = 4;
    int a_count = k.length() - 1;
    
    //count down by sixes
    for (int i = k.length() - 1; i >= 0; i -= 6)
    {
        long long a[6] = {0, 0, 0, 0, 0, 0};
        
        //go through each letter (as long as we're not over the limit) and convert it to an integer
        for (int j = 0; j < 6; j++)
        {
            if (a_count < 0)
                break;
            else {
                a[j] = k[i-j]-96;
                a_count--;
            }
        }
        
        //set each index of the w array to the hash algorithm
        w[w_count] = pow(27,5)*a[5] + pow(27,4)*a[4] + pow(27,3)*a[3] + pow(27,2)*a[2] + 27*a[1] + a[0];
        w_count--;
    }
    
    long long val = r1*w[0] + r2*w[1] + r3*w[2] + r4*w[3] + r5*w[4];

    return val % m;
}

