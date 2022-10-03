// 907. Sum of Subarray Minimums
// Medium

// 4239

// 280

// Add to List

// Share
// Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.

 

// Example 1:

// Input: arr = [3,1,2,4]
// Output: 17
// Explanation: 
// Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
// Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
// Sum is 17.
// Example 2:

// Input: arr = [11,81,94,43,3]
// Output: 444
 

// Constraints:

// 1 <= arr.length <= 3 * 104
// 1 <= arr[i] <= 3 * 104

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) 
    {
        stack<pair<int, int>> in_stk_p, in_stk_n;

        // left is for the distance to previous less element
        // right is for the distance to next less element

        vector<int> left(arr.size()), right(arr.size());

        //initialize

        for (int i = 0; i < arr.size();i++) left[i] = i++;
        for (int i = 0; i < arr.size();i++) right[i] = arr.size() - i;

        for (int i = 0; i < arr.size();i++)
        {

            // for previous less element

                    // C++ code (by slitghly modifying the paradigm):
                    // Instead of directly pushing the element itself, here for simplicity, we push the index.
                    // We do some record when the index is pushed into the stack.
                    // // previous_less[i] = j means A[j] is the previous less element of A[i].
                    // // previous_less[i] = -1 means there is no previous less element of A[i].
                    // vector<int> previous_less(A.size(), -1);
                    // for(int i = 0; i < A.size(); i++){
                    //   while(!in_stk.empty() && A[in_stk.top()] > A[i]){
                    //     in_stk.pop();
                    //   }
                    //   previous_less[i] = in_stk.empty()? -1: in_stk.top();
                    //   in_stk.push(i);
                    // }

            while(!in_stk_p.empty() && in_stk_n.top().first > arr[i])
                in_stk_p.pop();

            left[i] = in_stk_p.empty() ? i + 1 : i - in_stk_p.top().second;
            in_stk_p.push({arr[i], i});

            // for next less element

                    // C++ code (by slighly modifying the paradigm):
                    // We do some record when the index is poped out from the stack.
                    // // next_less[i] = j means A[j] is the next less element of A[i].
                    // // next_less[i] = -1 means there is no next less element of A[i].
                    // vector<int> previous_less(A.size(), -1);
                    // for(int i = 0; i < A.size(); i++){
                    // while(!in_stk.empty() && A[in_stk.top()] > A[i]){
                    //     auto x = in_stk.top(); in_stk.pop();
                    //     next_less[x] = i;
                    // }
                    // in_stk.push(i);
                    // }

            while(!in_stk_n.empty() && in_stk_n.top().first > arr[i])
            {
                auto x = in_stk_n.top();
                in_stk_n.pop();
                right[x.second] = i - x.second;
            }
            in_stk_n.push({arr[i], i});
        }

                    // we have an array: A = [2, 9, 7, 8, 3, 4, 6, 1], and we want to find how many subarrays of A has minimum number is 3.

                    // Let's assume distance between 3 to 2 (minimum number to first number greater 3 to the left (3 -> 9)) is m.
                    // and distance between 3 to 1 (minimum number to first number greater 3 to the right (3 -> 6)) is n.
                    // So the array A has total length m + n - 1 (3 appears twice)
                    // image

                    // The number of subarray we have for the array A with length m + n - 1 is 1 + 2 + 3 + 4 + ... + m + n - 1 = Summation(1 + (m + n - 1)), which is equal difference series sum S3 = n (a1 + an) / 2 = (m + n - 1) (m + n - 1 + 1) / 2 = (m + n - 1) (m + n) / 2

                    // Since 3 is the minimum number and we need to subtract number of subarrays which exclusive 3, which are subarrays [9,7,8] with length 3 or m - 1 and [4,6] with length 2 or n - 1, number of subarrays for [9,7,8] is S1 = (m - 1 + 1)(m - 1) / 2 = m(m - 1) / 2 and for [4,6] is S2 = n(n - 1) / 2

                    // Finally, we have

                    // S3 - S2 - S1 = (m + n - 1)(m + n)/2 - m(m - 1)/2 - n(n - 1)/2 
                    //                     = (n^2 + mn - n + mn + m^2 - m - n^2 + n - m^2 + m) / 2
                    //                     = 2mn / 2
                    //                     = mn 

        int ans = 0;
        int mod = 1e9 + 7;
        for (int i = 0; i < arr.size();i++)
        {
            ans = (ans + arr[i] * left[i] * right[i]) % mod;
        }
        return ans;
    }
};


// This is a variation of Calculate Contribution of each element type of problem

// In this type of problems where we need to find something such as min element, unique chars etc in all the possible substrings/subarrays and then we need to return the sum of all the results from each subarrays/substrings.

// So, here we need to calculate the CONTRIBUTION of each element in the total answer. We need to find the ending point in left as well as right side.

//   X X (X |E| X X X) X   
//   -> Here '(' is the last valid end point on left side for E
//   -> ')' is the last valid end point on right side for E
// To get the contribution : which means the total number of substrings/subarray this element will be part of , we use the below formula

//   contribution[i] = left[i] * right[i]  
//   -> left[i] & right[i] is length of last possible bracket on left and right side resp.
// Lets see with example : X X (X |E| X X) X , here left(E) = 2 & right(E) = 3

// So number of possible substrings/subarrays this element E will be part of is equal to 2*3 = 6 . How ?
// For every left(E) number of parts in left side we have choice of picking right(E) number of parts.

//   X X (A |B| C D) X X : so possible substrings with B in it are 
//   	-> {B}, {BC}, {BCD} , {AB}, {ABC}, {ABCD}  
// Thus using the above technique, we can simply solve these type of problems in Linear time. Just we need to calculate left and right end points of every element beforhand. Rest answer will be contribution of each item.

// Now coming back to this problem, we know that for every element we need the minimum of every subarray. So, we can find the next smallest element to left and right for each item.
// And the calculate the contribution.
// contribution[i] = left[i] * right[i] * arr[i]

// Since we need to pick the element which is minimum, so select that subarray in which current element is minimum.

// 	Ex: 1 ( 3 |2| 4 5 )  0  -> Here current element is 2. 
// 	-> left is untill we find the next smaller element than 2 to its left : left[i] = 2
// 	-> right is also until we find next smaller element than 2 to its right : right[i] = 3
// 	=> contribution = 2 * 3 = 6 , possible subarrays {2}, {2,4}, {2,4,5}, {3,2}, {3,2,4}, {3,2,4,5} 
// To find the next smaller element to left and right, And also learn about Monotonic stack.
// For this, we maintain a increasing stack from left for NEXT SMALLER ELEMENT TO LEFT. Also, similar stack for NEXT SMALLER ELEMENT TO RIGHT. These stack will store the index so that when calculating contribution, we will get the distance on left as well as right side.

// Code :
int sumSubarrayMins(vector<int>& arr) {
        
        int n = arr.size();
        
        vector<int> left(n,-1), right(n,n);
        // for every i find the Next smaller element to left and right
        
        // Left
        stack<int> st;
        for(int i=0; i<n; i++)
        {
            while(st.size() && arr[i] < arr[st.top()]) st.pop();
            if(st.size()) left[i] = i - st.top();
            else left[i] = i+1;
            st.push(i);
        }
        
        while(st.size()) st.pop();
        
        // Right
        for(int i=n-1; i>=0; i--)
        {
            while(st.size() && arr[i] <= arr[st.top()]) st.pop();
            if(st.size()) right[i] = st.top() - i;
            else right[i] = n - i;
            st.push(i);
        }
        
        // for(int i=0; i<n; i++) cout << left[i] << " : " << right[i] << endl;
        
        // for each i, contribution is (Left * Right) * Element 
        
        int res = 0;
        for(int i=0; i<n; i++)
        {
            long long prod = (left[i]*right[i])%MOD;
            prod = (prod*arr[i])%MOD;
            res = (res + prod)%MOD;
        }
        
        return res%MOD;
    }
// **Time : O(N + N + N) = O(3N) ~ O(N)
// Space : O(3N) ~ O(N)
// **


// class Solution {
// public:
//     int sumSubarrayMins(vector<int>& arr) {
//         stack<int> s1, s2;
//         int n = arr.size();
//         vector<int> next_smaller(n), prev_smaller(n);
        
        
//         for(int i = 0;i<n;i++){
//             next_smaller[i] = n-i-1;
//             prev_smaller[i] = i;
//         }
        
        
//         for(int i = 0;i<n;i++){
//             while(!s1.empty() && arr[s1.top()]>arr[i]){
//                 next_smaller[s1.top()] = i - s1.top() - 1;
//                 s1.pop();
//             }
//             s1.push(i);
//         }
        
//         for(int i = n-1;i>=0;i--){
//             while(!s2.empty() && arr[s2.top()]>=arr[i]){
//                 prev_smaller[s2.top()] = s2.top() - i - 1;
//                 s2.pop();
//             }
//             s2.push(i);
//         }
        
//         long ans = 0;
//         int mod = 1e9 + 7;
        
//         for(int i = 0;i<n;i++){
//             ans = (ans + (long)arr[i] * (prev_smaller[i]+1) * (next_smaller[i]+1)) % mod;
//             ans %= mod;
//         }
        
//         return ans;
//     }
// };