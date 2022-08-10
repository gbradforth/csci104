/*
 CSCI 104 Homework 1
 Gwen Bradforth

 */
#include <iostream>

using namespace std;

void permuteHelper(string in, int b, int e) {
    if (b == e)
        cout << in << endl;  // if the beginning is the end, print the string that should be a permutation
    else {
        for (int i = b; i <= e; i++) {
            swap(in[b], in[i]);           // swap the two letters (if they're the same, that's fine)
            permuteHelper(in, b + 1, e);  // permute a shorter string
            swap(in[b], in[i]);           // swap the two letters
        }
    }
}

void permutations(string in) { permuteHelper(in, 0, in.length() - 1); }

void swap(string in, int i, int j) {
    char temp = in[i];
    in[i] = in[j];
    in[j] = temp;
}
