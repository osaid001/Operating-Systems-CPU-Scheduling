#include "DeadlockManager.h"

using namespace std;

rec::rec() : c(' '), free(false) {}
rec::rec(char c) : c(c), free(false) {}

DeadlockManager::DeadlockManager() : recourcesss(nullptr) {}

DeadlockManager::~DeadlockManager()
{
    if (recourcesss != nullptr)
    {
        for (int i = 0; i < sizeof(recourcesss) / sizeof(rec*); i++)
        {
            delete recourcesss[i];
        }
        delete[] recourcesss;
    }
}

bool DeadlockManager::checkrepetitions(int total_rec, int totalproc, string* alloc)
{
    recourcesss = new rec * [total_rec];
    for (int i = 0; i < total_rec; i++)
    {
        char x = i + '0' + 1;
        recourcesss[i] = new rec(x);
    }

    for (int i = 0; i < totalproc; i++)
    {
        string s1 = alloc[i];
        for (char c : s1)
        {
            if (c != ' ' && c != ',')
            {
                for (int j = 0; j < total_rec; j++)
                {
                    if (c == recourcesss[j]->c)
                    {
                        if (!recourcesss[j]->free)
                        {
                            recourcesss[j]->free = true;
                        }
                        else
                        {
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

bool DeadlockManager::checkrange(int total_rec, int totalproc, string* alloc, string* need)
{
    for (int i = 0; i < totalproc; i++)
    {
        string s = alloc[i];
        for (char c : s)
        {
            if (c != ' ' && c != ',')
            {
                int x = c - '0';
                if (x <= total_rec && x > 0)
                {
                }
                else
                {
                    return false;
                }
            }
        }

        string s1 = need[i];
        for (char c1 : s1)
        {
            if (c1 != ' ' && c1 != ',')
            {
                int x = c1 - '0';
                if (x <= total_rec && x > 0)
                {
                }
                else
                {
                    return false;
                }
            }
        }
    }
    return true;
}

void DeadlockManager::freerec(int total_rec, int totalproc, string* alloc)
{
    for (int i = 0; i < total_rec; i++)
    {
        recourcesss[i]->free = true;
    }

    for (int i = 0; i < totalproc; i++)
    {
        string s = alloc[i];
        for (char c : s)
        {
            if (c != ' ' && c != ',')
            {
                for (int j = 0; j < total_rec; j++)
                {
                    if (c == recourcesss[j]->c)
                    {
                        recourcesss[j]->free = false;
                    }
                }
            }
        }
    }
}

void DeadlockManager::setfree(string s, int total_rec)
{
    for (char c : s)
    {
        if (c != ' ' && c != ',')
        {
            for (int i = 0; i < total_rec; i++)
            {
                if (c == recourcesss[i]->c)
                {
                    recourcesss[i]->free = true;
                }
            }
        }
    }
}

bool DeadlockManager::chkdeadlock(int total_rec, int totalproc, int* procseq, string* alloc, string* need)
{
    freerec(total_rec, totalproc, alloc);
    int ps;
    string s, s1;
    vector<char> procrec;

    for (int i = 0; i < totalproc; i++)
    {
        ps = procseq[i];
        s = need[ps - 1];
        s1 = alloc[ps - 1];
        for (char c : s)
        {
            if (c != ' ' && c != ',')
            {
                procrec.push_back(c);
            }
        }

        for (auto it = procrec.begin(); it != procrec.end(); )
        {
            bool erased = false;
            for (char c : s1)
            {
                if (*it == c)
                {
                    it = procrec.erase(it);
                    erased = true;
                    break;
                }
            }
            if (!erased)
            {
                ++it;
            }
        }

        if (!procrec.empty())
        {
            for (auto it = procrec.begin(); it != procrec.end(); )
            {
                bool erased = false;
                for (int k = 0; k < total_rec; k++)
                {
                    if (*it == recourcesss[k]->c && recourcesss[k]->free)
                    {
                        it = procrec.erase(it);
                        erased = true;
                        break;
                    }
                }
                if (!erased)
                {
                    ++it;
                }
            }
        }

        if (procrec.empty())
        {
            setfree(s1, total_rec);
        }
        else
        {
            return true;
        }
    }
    return false;
}
