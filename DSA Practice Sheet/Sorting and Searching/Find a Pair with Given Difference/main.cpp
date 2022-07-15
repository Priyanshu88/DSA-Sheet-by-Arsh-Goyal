// Naive Solution: The simplest method is to run two loops, the outer loop 
// picks the first element (smaller element) and the inner loop looks 
// for the element picked by outer loop plus n. Time complexity of this method is O(n2)


// Better Solution : Sorting the array in ascending order
// taking 2 index variables i and j initialize them as 0 and 1. then doing binary search if diff is equal to n
// and i is not equal to j then pair found return true
// else if diff is greater than n then we need to look for higher arr[i] so increment i
// else diff is smaller than n than we need to look for higher arr[j] so increment j
// if not found return false

#include <bits/stdc++.h>
using namespace std;

bool findPair(int arr[], int size, int n)
{

    sort(arr, arr+size);
    int i = 0;
    int j = 1;

    while(i <= j && j < size)
    {
        int diff = arr[j]-arr[i];
        if(i != j && diff == n)
        {
            cout << "Pair is: {" << arr[i] << ", " << arr[j] << "}";
            return true;
        }
        else if(diff > n)
        {
            i++;
        }
        else 
        {
            j++;
        }
        return false;

}


// T.C. :O(n log n)



// Creating an empty hash table. Traversing the array, using array elements
// as hash keys and enter them in hash. Check if any element whose frequency
// is greater than 1 exist or not for n == 0 . Check if difference is zero and
// we are unable to find any duplicate or element whose frequency is greater than 1
// then no such pair found.Traverse the array again look for
// value n + arr[i] in Hash


#include <bits/stdc++.h>
using namespace std;

bool findPair(int arr[], int size, int n)
{
    unordered_map<int,int> mp;

    for(int i =0;i<size;i++)
    {
        mp[arr[i]]++;

        if(n == 0 && mp[arr[i]] > 1)
            return true;
    }


    if(n == 0)
    return false;
    
    for(int i=0;i<size;i++)
    {
        if(mp.find(n+arr[i]) != mp.end())
        {

            cout << "Pair is: {" << arr[i] << ", " << n+arr[i] << "}";
            return true;
        }
    }

    return false;

}


// T.C. : O(n)
// S.C. : O(n)


