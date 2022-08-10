/*
 CSCI 104 Homework 1
 Gwen Bradforth

 */
#include "company.hpp"
#include <iostream>

using namespace std;

int main() {
    int c = 0;

    CompanyTracker ct = CompanyTracker(5);
    cout << "Company Tracker initialized!" << endl;
    c++;

    cout << "Attempting to split a 1 person company!" << endl;
    ct.split(2);  // should do nothing, 1 person company
    c++;

    cout << "Attempting to split an out of range integer!" << endl;
    ct.split(6);  // shouldn't work, out of range
    c++;

    cout << "Merging 3 and 4" << endl;
    ct.merge(3, 4);
    if (ct.inSameCompany(3, 4))
        c++;
    cout << "3 and 4 in the same company: " << ct.inSameCompany(3, 4) << endl;  // should be true

    cout << "Attempting to merge out of range!" << endl;
    ct.merge(3, 6);  // shouldn't do anything, 6 out of range
    c++;

    cout << "Attempting to merge 3 and 4 again!" << endl;
    ct.merge(3, 4);  // shouldn't do anything, already merged
    if (ct.inSameCompany(3, 4))
        c++;
    cout << "3 and 4 in the same company: " << ct.inSameCompany(3, 4) << endl;  // should be true

    cout << "Splitting 3!" << endl;
    ct.split(3);
    if (!ct.inSameCompany(3, 4))
        c++;
    cout << "3 and 4 in the same company: " << ct.inSameCompany(3, 4) << endl;  // should be false

    cout << "Merging 0 and 3!" << endl;
    ct.merge(0, 3);
    if (ct.inSameCompany(3, 0))
        c++;
    cout << "3 and 0 in the same company: " << ct.inSameCompany(3, 0) << endl;  // should be true

    cout << "Merging 2 and 4!" << endl;
    ct.merge(2, 4);
    if (ct.inSameCompany(2, 4))
        c++;
    cout << "2 and 4 in the same company: " << ct.inSameCompany(2, 4) << endl;  // should be true

    cout << "Merging 0 and 4" << endl;
    ct.merge(0, 4);
    if (ct.inSameCompany(3, 2))
        c++;
    cout << "3 and 2 in the same company: " << ct.inSameCompany(3, 2) << endl;  // should be true

    cout << "Splitting 3" << endl;
    ct.split(3);
    if (!ct.inSameCompany(0, 4))
        c++;
    cout << "0 and 4 in the same company: " << ct.inSameCompany(0, 4) << endl;  // should be false

    cout << "Splitting 3" << endl;
    ct.split(3);
    if (!ct.inSameCompany(0, 3))
        c++;
    cout << "0 and 3 in the same company: " << ct.inSameCompany(0, 3) << endl;  // should be false

    if (ct.inSameCompany(2, 4))
        c++;
    cout << "2 and 4 in the same company: " << ct.inSameCompany(0, 3) << endl;  // should be true

    cout << "passed " << c << "/13 tests" << endl;
}