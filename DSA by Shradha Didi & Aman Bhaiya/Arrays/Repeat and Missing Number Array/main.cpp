// Repeat and Missing Number Array

// There are certain problems which are asked in the interview to also check how you take care of overflows in your problem.

// This is one of those problems.

// Please take extra care to make sure that you are type-casting your ints to long properly and at all places. Try to verify if your solution works if number of elements is as large as 105

// Food for thought :

// Even though it might not be required in this problem, in some cases, you might be required to order the operations cleverly so that the numbers do not overflow.
// For example, if you need to calculate n! / k! where n! is factorial(n), one approach is to calculate factorial(n), factorial(k) and then divide them.
// Another approach is to only multiple numbers from k + 1 ... n to calculate the result.
// Obviously approach 1 is more susceptible to overflows.
// You are given a read only array of n integers from 1 to n.

// Each integer appears exactly once except A which appears twice and B which is missing.

// Return A and B.

// Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

// Note that in your output A should precede B.

// Example:

// Input:[3 1 2 5 3]

// Output:[3, 4]

// A = 3, B = 4

#include <bits/stdc++.h>
using namespace std;

vector<int> Solution::repeatedNumber(const vector<int> &A)
{
    long long int len = A.size();
    long long int sum_n = (len * (len + 1)) / 2, sum_SqN = (len * (len + 1) * (2 * len + 1)) / 6;
    long long int missingNum = 0, repeatingNum = 0;
    for (int i = 0; i < A.size(); i++)
    {
        sum_n -= (long long int)A[i];
        sum_SqN -= (long long int)A[i] * (long long int)A[i];
    }
    missingNum = (sum_n + sum_SqN / sum_n) / 2;
    repeatingNum = missingNum - sum_n;
    vector<int> ans;
    ans.push_back(repeatingNum);
    ans.push_back(missingNum);
    return ans;
}

class Solution
{
public:
    int *findTwoElement(int *arr, int n)
    {

        long long int len = n;
        long long int sum_n = (len * (len + 1)) / 2, sum_SqN = (len * (len + 1) * (2 * len + 1)) / 6;
        long long int missingNum = 0, repeatingNum = 0;
        for (int i = 0; i < len; i++)
        {
            sum_n -= (long long int)arr[i];
            sum_SqN -= (long long int)arr[i] * (long long int)arr[i];
        }
        missingNum = (sum_n + (sum_SqN / sum_n)) / 2;
        repeatingNum = missingNum - sum_n;
        int *ans;
        ans[0] = repeatingNum;
        ans[1] = missingNum;
        return ans;
    }
};

class Solution
{
public:
    int *findTwoElement(int *arr, int n)
    {
        int *ans = new int[2], i;
        for (int i = 0; i < n; i++)
        {
            if (arr[abs(arr[i]) - 1] > 0)
            {
                arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
            }
            else
            {
                ans[0] = abs(arr[i]);
            }
            for (i = 0; i < n; i++)
            {
                if (arr[i] > 0)
                    ans[1] = i + 1;
            }
        }
        return ans;
    }
};
