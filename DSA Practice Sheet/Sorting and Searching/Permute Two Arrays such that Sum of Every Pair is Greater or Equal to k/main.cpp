#include <bits/stdc++.h>
using namespace std;

// sorting both the arrays a in ascending and b in descending order
// if any index does not satisfy the condition a[i]+b[i] >= k then return false otherwise return true

bool isPossible(int a[], int b[], int n, int k)
{
    sort(a,a+n);
    sort(b,b+n,greater<int>());
    for(int i=0;i<n;i++)
    {
        if(a[i]+b[i] < k)
        return false;
    }
    return true;
}


// T.C.O(n log n)