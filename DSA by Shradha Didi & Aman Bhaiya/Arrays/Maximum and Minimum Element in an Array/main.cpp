// Max Min
// Given an array A of size N of integers. Your task is to find the sum of minimum and maximum elements in the array.

// Example 1:

// Input:
// N = 5
// A[] = {-2, 1, -4, 5, 3}
// Output: 1
// Explanation: min = -4, max =  5. Sum = -4 + 5 = 1

// Example 2:

// Input:
// N = 4
// A[]  = {1, 3, 4, 1}
// Output: 5
// Explanation: min = 1, max = 4. Sum = 1 + 4 = 5

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function findSum() which takes the array A[] and its size N as inputs and returns the summation of minimum and maximum element of the array.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= N <= 105
// -109 <= Ai <= 109

#include <iostream>
using namespace std;

// Pair struct is used to return
// two values from getMinMax()

struct Pair
{
    int min;
    int max;
};

Pair getMinMax(int arr[], int n)
{
    struct Pair minmax;
    int i;

    // If there is only one element
    // then return it as min and max both

    if (n == 1)
    {
        minmax.max = arr[0];
        minmax.min = arr[0];
        return minmax;
    }

    // If there are more than one elements,
    // then initialize min and max

    if (arr[0] > arr[1])
    {
        minmax.max = arr[0];
        minmax.min = arr[1];
    }

    else
    {
        minmax.max = arr[1];
        minmax.min = arr[0];
    }

    for (int i = 2; i < n; i++)
    {
        if (arr[i] > minmax.max)
            minmax.max = arr[i];

        else if (arr[i] < minmax.min)
            minmax.min = arr[i];
    }
    return minmax;
}

class Solution
{
public:
    int findSum(int A[], int n)
    {
        // code
        sort(A, A + n);
        int sum = A[0] + A[n - 1];
        return sum;
    }
};

class Solution
{
public:
    int findSum(int A[], int n)
    {
        int Max = INT_MIN;
        int Min = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (A[i] > Max)
            {
                Max = A[i];
            }
            if (A[i] < Min)
            {
                Min = A[i];
            }
        }
        return Max + Min;
    }
};

// n%2 is equaivalent to n&1

class Solution
{
public:
    int findSum(int A[], int n)
    {
        int Max, Min;
        int i;
        if (n % 2 != 0)
        {
            Max = A[0];
            Min = A[0];
            i = 1;
        }
        else
        {
            if (A[0] < A[1])
            {
                Max = A[1];
                Min = A[0];
            }
            else
            {
                Max = A[0];
                Min = A[1];
            }

            i = 2;
        }

        while (i < n)
        {

            if (A[i] < A[i + 1])
            {
                if (A[i] < Min)
                {
                    Min = A[i];
                }
                if (A[i + 1] > Max)
                {
                    Max = A[i + 1];
                }
            }
            else
            {
                if (A[i] > Max)
                {
                    Max = A[i];
                }
                if (A[i + 1] < Min)
                {
                    Min = A[i + 1];
                }
                i = i + 2;
            }
            return Min + Max;
        }
    }
};