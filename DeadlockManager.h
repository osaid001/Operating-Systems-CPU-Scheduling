#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct rec
{
    char c;
    bool free;
    rec();
    rec(char c);
};

class DeadlockManager
{
    rec** recourcesss;

public:
    DeadlockManager();
    ~DeadlockManager();
    bool checkrepetitions(int total_rec, int totalproc, string* alloc);
    bool checkrange(int total_rec, int totalproc, string* alloc, string* need);
    void freerec(int total_rec, int totalproc, string* alloc);
    void setfree(string s, int total_rec);
    bool chkdeadlock(int total_rec, int totalproc, int* procseq, string* alloc, string* need);
};
