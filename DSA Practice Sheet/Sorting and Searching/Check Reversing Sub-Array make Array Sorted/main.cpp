// Naive Solution: Consider every subarray and check if reversing the subarray makes the 
// whole array sorted. If yes, return True. If reversing any of the subarrays
// doesn’t make the array sorted, then return False. Considering every subarray
// will take O(n2), and for each subarray, checking whether the whole array will
// get sorted after reversing the subarray in consideration will take O(n). 
// Thus overall complexity would be O(n3).



// Creating an auxiliary array temp copying all the elements of arr 
// then sorting the array finding the first mismatch from starting and last 
// mismatch from with the sorted array end if the array is sorted means return true
// else checking if the elements between the found indices are in decreasing order, if yes then return true  otherwise false


#include<bits/stdc++.h>
using namespace std;


bool checkReverse(int arr[], int n)
{

    // copying the array

    int temp[n];
    for(int i=0;i<n;i++)
    {
        temp[n] = arr[i];
    }

    // sort the copied array
    
    sort(temp, temp+n);

    // finding the first mismatch

    int first;

    for(first = 0;first<n;first++)
    {
        if(temp[first] != arr[first])
        break;
    }

    // finding the last mismatch

    int back;

    for(int back = n-1;back >=0;back--)
    {
        if(temp[back] != arr[back])
        break;
    }

    // if whole array is sorted

    if(first >= back)
    return true;

    // checking subarray is decreasing or not

    do 
    {
        first++;
        if(arr[first-1] < arr[first])
        return false;
    }
    while(first != back);
    return true;

}


// T.C.: O (n log n)
// S.C.:O (n)


// returning true when the array is already sorted or when the array consists of 
// three parts the first part is increasing subarray, then decreasing subarray, and then again 
// increasing subarray. so we need to check that array contains increasing elements then some decreasing elements,
// and then increasing  and we wil handle the validity of three parts then answer will be True. 
// in all other cases, the answer will be False.

bool checkReverse(int arr[], int n)
{
    if(n == 1)
    return true;

    int i;

    // finding the first increasing part

    for(i=1; i<n && arr[i-1] < arr[i]; i++)
    if(i == n)
    return true;

    // finding the reversed part

    int j=i;
    while(j < n && arr[j] < arr[j-1])
    {
        if(i > 1 && arr[j] < arr[i-2])
        return false;
        j++;
    }

    if(j == n)
    return true;

    // finding last increasing part

    int k = j;

    // check for validity

    if(arr[k] < arr[i-1])
    return false;

    while(k > 1 && k < n)
    {
        if(arr[k] < arr[k-1])
        return false;
        k++;
    }
    return true;
}

// T.C.:O(n)
// S.C. :O(1)