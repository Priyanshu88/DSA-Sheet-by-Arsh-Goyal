// Find maximum of minimum for every window size in a given array

// Difficulty Level : Expert
// Last Updated : 26 Sep, 2022
// Given an integer array of size n, find the maximum of the minimum’s of every window size in the array. Note that window size varies from 1 to n.

// Example:

// Input: arr[] = {10, 20, 30, 50, 10, 70, 30} 
// Output: 70, 30, 20, 10, 10, 10, 10
// The first element in the output indicates the maximum of minimums of all 
// windows of size 1. 
// Minimums of windows of size 1 are {10}, {20}, {30}, {50}, {10}, 
// {70} and {30}. Maximum of these minimums is 70
// The second element in the output indicates the maximum of minimums of all 
// windows of size 2. 
// Minimums of windows of size 2 are {10}, {20}, {30}, {10}, {10}, 
// and {30}. Maximum of these minimums is 30
// The third element in the output indicates the maximum of minimums of all 
// windows of size 3. 
// Minimums of windows of size 3 are {10}, {20}, {10}, {10} and {10}. 
// Maximum of these minimums is 20
// Similarly, other elements of output are computed. 


// Approach: A simple brute force approach to solve this problem can be to generate all the windows possible of a particular length say ‘L’ and find 
// the minimum element in all such windows. Then find the maximum of all such elements and store it. Now the length of window is 1<=L<=N. So we have to generate all 
// possible windows of size ‘1’ to ‘N’ and for generating each such window we have to mark the end-points of that window. So for that, we have to use a nested loop for 
// fixing the starting and end point of the window respectively. Therefore there will be a use of triple-nested loop in brute-force approach mainly for fixing the length of the window, starting point and end point.

#include<bits/stdc++.h>
using namespace std;

void printMaxofMin(int arr[], int n)
{

    // Consider all windows of different
    // sizes starting from size 1

    for (int k = 1; k <= n;k++)
    {

        // Initialize max of min for
        // current window size k

        int maxOfMin = INT_MIN;

        // Traverse through all windows
        // of current size k

        for(int i= 0;i<=n-k;i++)
        {

            // Find minimum of current window

            int min = arr[i];

            for (int j = 1; j < k;j++)
            {

                if(arr[i+j] < min)
                {
                    min = arr[i + j];
                }
            }

            // Update maxOfMin if required

            if(min > maxOfMin)
            {
                maxOfMin = min;
            }
        }

        // Print max of min for current
        // window size

        cout << maxOfMin << " ";

    }
}

// Complexity Analysis:  

// Time Complexity: O(n3). 
// As there is a use of triple nested loop in this approach.
// Auxiliary Space: O(1) 
// As no extra data structure has been used to store the values.


// Step 1: 

// Find indexes of next smaller and previous smaller for every element. Next smaller is the nearest smallest element on right side of arr[i]. Similarly, a previous smaller element is the nearest smallest element on the left side of arr[i]. 
// If there is no smaller element on the right side, then the next smaller is n. If there is no smaller on the left side, then the previous smaller is -1.
// For input {10, 20, 30, 50, 10, 70, 30}, array of indexes of next smaller is {7, 4, 4, 4, 7, 6, 7}. 
// For input {10, 20, 30, 50, 10, 70, 30}, array of indexes of previous smaller is {-1, 0, 1, 2, -1, 4, 4}
// This step can be done in O(n) time using the approach discussed in next greater element.
// Step 2: 

// Once we have indexes of next and previous smaller, we know that arr[i] is a minimum of a window of length “right[i] – left[i] – 1”. Lengths of windows
//  for which the elements are minimum are {7, 3, 2, 1, 7, 1, 2}. This array indicates, the first element is minimum in the window of size 7, the second element is minimum in the window of size 3, and so on.

// Create an auxiliary array ans[n+1] to store the result. Values in ans[] can be filled by iterating through right[] and left[] 

//     for (int i=0; i < n; i++)
//     {
//         // length of the interval
//         int len = right[i] - left[i] - 1;

//         // arr[i] is a possible answer for
//         // this length len interval
//         ans[len] = max(ans[len], arr[i]);
//     }
// We get the ans[] array as {0, 70, 30, 20, 0, 0, 0, 10}. Note that ans[0] or answer for length 0 is useless.

// Step 3: 

// Some entries in ans[] are 0 and yet to be filled. For example, we know maximum of minimum for lengths 1, 2, 3 and 7 are 70, 30, 20 and 10 respectively, but we don’t know the same for lengths 4, 5 and 6. 

// Note: We perform the following step even if we do not have any remaining entries to fill. The reason is that some entries may be wrongly set to a lower maximum value of the minimum of every window of size ‘x’. 
// There might be a case where the maximum value of the minimum of every window of size ‘x’ may be lower than the maximum of every window of size ‘y’ where x<y. In such a case, we need to select the maximum of the two and place it in ans[x]. e.g. 
// Consider the input 50 60 70 50 90 80 100. 
// If we do not perform the following operation ans[2] will be 60 instead of 80 (considering 1-based indexing).

// Below are few important observations to fill remaining entries

// Result for length i, i.e. ans[i] would always be greater or same as result for length i+1, i.e., ans[i+1]. 
// If ans[i] is not filled it means there is no direct element which is minimum of length i and therefore either the element of length ans[i+1], or ans[i+2], and so on is same as ans[i] 
// So we fill rest of the entries using below loop.
//     for (int i=n-1; i>=1; i--)
//         ans[i] = max(ans[i], ans[i+1]);


void printMaxOfMin(int arr[],int n)
{

    // Used to find previous and next smaller

    stack<int> s;

    // Arrays to store previous and next smaller

    int left[n + 1];
    int right[n + 1];

    // Initialize elements of left[] and right[]

    for (int i = 0; i < n;i++)
    {
        left[i] = -1;
        right[i] = n;
    }

    for (int i = 0; i < n;i++)
    {

        while(!s.empty() && arr[s.top() >= arr[i]])
            s.pop();
        if(!s.empty())
            left[i] = s.top();
        s.push(i);
    }

    // Empty the stack as stack is
    // going to be used for right[]

    while(!s.empty())
    {
        s.pop();
    }

    // Fill elements of right[] using same logic
    
    for (int i = n - 1; i >= 0;i--)
    {
            while(!s.empty() && arr[s.top()] >= arr[i])
                s.pop();
            if(!s.empty())
                right[i] = s.top();
            s.push(i);
    }

    // Create and initialize answer array


    int ans[n + 1];
    for (int i = 0; i <= n;i++)
        ans[i] = 0;

    // Fill answer array by comparing minimums of all
    // lengths computed using left[] and right[]

    for (int i = 0; i < n;i++)
    {

        // length of the interval

        int len = right[i] - left[i] - 1;

        // arr[i] is a possible answer for this length
        // 'len' interval, check if arr[i] is more than
        // max for 'len'

        ans[len] = max(ans[len], arr[i]);
    }

    // Some entries in ans[] may not be filled yet. Fill
    // them by taking values from right side of ans[]

    for (int i = n - 1; i >= 1;i--)
        ans[i] = max(ans[i], ans[i + 1]);

    // Print the result

    for (int i = 1; i <= n;i++)
    {
        cout << ans[i] << " ";
    }
}

// Complexity Analysis:  

// Time Complexity: O(n). 
// Every sub-task in this approach takes Linear time.
// Auxiliary Space : O(n). 
// Use of stack for calculating next minimum and arrays to store the intermediate results.

// Maximum of minimum for every window size
// HardAccuracy: 53.43%Submissions: 17756Points: 8
// Given an integer array. The task is to find the maximum of the minimum of every window size in the array.
// Note: Window size varies from 1 to the size of the Array.

// Example 1:

// Input:
// N = 7
// arr[] = {10,20,30,50,10,70,30}
// Output: 70 30 20 10 10 10 10 
// Explanation: 
// 1.First element in output
// indicates maximum of minimums of all
// windows of size 1.
// 2.Minimums of windows of size 1 are {10},
//  {20}, {30}, {50},{10}, {70} and {30}. 
//  Maximum of these minimums is 70. 
// 3. Second element in output indicates
// maximum of minimums of all windows of
// size 2. 
// 4. Minimums of windows of size 2
// are {10}, {20}, {30}, {10}, {10}, and
// {30}.
// 5. Maximum of these minimums is 30 
// Third element in output indicates
// maximum of minimums of all windows of
// size 3. 
// 6. Minimums of windows of size 3
// are {10}, {20}, {10}, {10} and {10}.
// 7.Maximum of these minimums is 20. 
// Similarly other elements of output are
// computed.
// Example 2:

// Input:
// N = 3
// arr[] = {10,20,30}
// Output: 30 20 10
// Explanation: First element in output
// indicates maximum of minimums of all
// windows of size 1.Minimums of windows
// of size 1 are {10} , {20} , {30}.
// Maximum of these minimums are 30 and
// similarly other outputs can be computed
// Your Task:
// The task is to complete the function maxOfMin() which takes the array arr[] and its size N as inputs and finds the maximum of minimum of every window size and returns an array containing the result. 

// Expected Time Complexity : O(N)
// Expected Auxiliary Space : O(N)

// Constraints:
// 1 <= N <= 105
// 1 <= arr[i] <= 106


class Solution
{
    public:

    //Function to find maximum of minimums of every window size.
    
    vector <int> maxOfMin(int arr[], int n)
    {
        
        // Your code here

        vector<int> ans;
    
    }
};