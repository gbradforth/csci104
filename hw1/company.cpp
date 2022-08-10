#include "company.hpp"

// Initializes the tracker with n students and their 1-person companies.
CompanyTracker::CompanyTracker(int n) {
    numCompanies = n;
    companies = new Company*[numCompanies];
    for (int i = 0; i < numCompanies; ++i)
        companies[i] = new Company();
}

// Deallocates all dynamically allocated memory.
CompanyTracker::~CompanyTracker() {
    for (int i = 0; i < numCompanies; i++) {
        // while the parent is not itself
        while (findLargestParent(i) != companies[i]) {
            // split the parent company(which deletes it)
            split(i);
        }
        // delete the company i
        delete companies[i];
    }
    delete[] companies;  // delete the company list
}

void CompanyTracker::merge(int i, int j) {
    // if i and j belong to the same company, do nothing, or if i and j are out of range
    if (inSameCompany(i, j) || i > numCompanies || j > numCompanies) {
    } else {
        // find the largest companies with i and j in them
        Company* iComp = findLargestParent(i);
        Company* jComp = findLargestParent(j);

        // make new company object (parent of i and j)
        Company* p = new Company(iComp, jComp);

        // make the i an j companies' parent p
        iComp->parent = p;
        jComp->parent = p;
    }
}

void CompanyTracker::split(int i) {
    if (i > numCompanies) {
    }  // If i is out of range, split doesn't do anything.

    // If i's largest company is a 1-person company,split doesn't do anything
    else if (findLargestParent(i) == companies[i]) {
    }

    else {
        // delete the largest parent of the
        Company* iLarge = findLargestParent(i);

        // makes sure that the two subcompanies have no parent afterwards
        iLarge->merge1->parent = nullptr;  //
        iLarge->merge2->parent = nullptr;

        // deletes the company object that i belongs to
        delete iLarge;
    }
}

bool CompanyTracker::inSameCompany(int i, int j) {
    // Returns false if i or j (or both) is out of range.
    if (i > numCompanies || j > numCompanies)
        return false;
    // returns true if the largest parent of i and j are the same
    else if (findLargestParent(i) == findLargestParent(j))
        return true;
    return false;
}

Company* CompanyTracker::findLargestParent(int i) {
    Company* p = companies[i];
    while (p->parent != nullptr)  // goes up the chain of parents until the last one has no parent
    {
        p = p->parent;
    }
    return p;  // when the last one has no parent, that is the largest company with i in it
}
