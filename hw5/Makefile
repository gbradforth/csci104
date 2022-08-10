all: hashtable

hashtable: hashtable.h birthday.cpp probe.cpp
	g++ -g -Wall -std=c++11 birthday.cpp -o hashtable

.PHONY: clean

clean:
	rm -f hashtable
