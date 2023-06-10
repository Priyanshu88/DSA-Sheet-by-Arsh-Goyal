#include <bits/stdc++.h>
using namespace std;

class LRUCache
{

    list<int> dq;
    unordered_map<int, list<int>::iterator> mp;
    int capacitysize;

public:
    LRUCache(int);
    void refer(int);
    void display();
};

LRUCache::LRUCache(int N)
{
    capacitysize = N;
}

void LRUCache::refer(int x)
{
    if (mp.find(x) == mp.end())
    {
        if (dq.size() == capacitysize)
        {
            int last = dq.back();
            dq.pop_back();
            mp.erase(last);
        }
    }
    else
    {
        dq.erase(mp[x]);
    }
    dq.push_front(x);
    mp[x] = dq.begin();
}

void LRUCache::display()
{
    for (auto it = dq.begin(); it != dq.end(); it++)
    {
        cout << (*it) << " ";
    }
    cout << endl;
}

int main()
{
    LRUCache ca(4);

    ca.refer(1);
    ca.refer(2);
    ca.refer(3);
    ca.refer(1);
    ca.refer(4);
    ca.refer(5);
    ca.display();

    return 0;
}
