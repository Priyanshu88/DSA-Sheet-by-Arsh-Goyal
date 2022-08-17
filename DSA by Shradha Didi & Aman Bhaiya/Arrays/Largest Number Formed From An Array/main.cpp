// Largest Number formed from an Array

// This problem is part of GFG SDE Sheet. Click here to view more.  

// Given a list of non negative integers, arrange them in such a manner that they form the largest number possible.The result is going to be very large, hence return the result in the form of a string.


// Example 1:

// Input: 
// N = 5
// Arr[] = {3, 30, 34, 5, 9}
// Output: 9534330
// Explanation: Given numbers are {3, 30, 34,
// 5, 9}, the arrangement 9534330 gives the
// largest value.
// Example 2:

// Input: 
// N = 4
// Arr[] = {54, 546, 548, 60}
// Output: 6054854654
// Explanation: Given numbers are {54, 546,
// 548, 60}, the arrangement 6054854654 
// gives the largest value.

// Your Task:  
// You don't need to read input or print anything. Your task is to complete the function printLargest() which takes the array of strings arr[] as parameter and returns a string denoting the answer.

// Expected Time Complexity: O(NlogN)
// Expected Auxiliary Space: O(1)


// Constraints:
// 1 ≤ N ≤ 105
// 0 ≤ Arr[i] ≤ 1018
// Sum of all the elements of the array is greater than 0.


#include<bits/stdc++.h>
using namespace std;


int myComp(string x,string y)
{
    string XY = x.append(y);
    string YX = y.append(x);
    return XY.compare(YX) > 0 ? 1 : 0;
}


bool Comp(string a, string b)
{
    return (a + b) > (b + a);
}

class Solution{
public:

	// The main function that returns the arrangement with the largest value as string.
	// The function accepts a vector of strings

	string printLargest(vector<string> &arr) 
    {
        sort(arr.begin(), arr.end(), Comp);
        string ans;
        for(string s: arr)
        {
            ans += s;
        }
        return ans;
    }
};