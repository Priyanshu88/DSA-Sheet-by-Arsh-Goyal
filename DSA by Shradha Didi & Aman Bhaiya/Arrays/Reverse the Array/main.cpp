// Reverse a String
// You are given a string s. You need to reverse the string.

// Example 1:

// Input:
// s = Geeks
// Output: skeeG
// Example 2:

// Input:
// s = for
// Output: rof
// Your Task:

// You only need to complete the function reverseWord() that takes s as parameter and returns the reversed string.

// Expected Time Complexity: O(|S|).
// Expected Auxiliary Space: O(1).

// Constraints:
// 1 <= |s| <= 10000


#include<bits/stdc++.h>
using namespace std;

void Reverse(int A[],int n)
{
    int low = 0;
    int high = n - 1;
    while (low < high)
    {
        int temp = A[low];
        A[low] = A[high];
        A[high] = temp;
        low++;
        high--;
    }
    for (int i = 0; i < n;i++)
    {
        cout << A[i];
    }
}

void RecReverse(int A[], int start, int end)
{
    if(start >= end)
        return;
    int temp = A[start];
    A[start] = A[end];
    A[end] = temp;

    RecReverse(A, start + 1, end-1);
    for (int i = 0; i < n;i++)
    {
        cout << A[i];
    }
}

string reverseWord(string str){

    
    int low = 0;
    int high = str.length()-1;
    while(low < high)
    {
        int temp = str[low];
        str[low] = str[high];
        str[high] = temp;
        low++;
        high--;
    }
    for(int i=0;i<str.length();i++)
    {
        cout << str[i];
    }
}