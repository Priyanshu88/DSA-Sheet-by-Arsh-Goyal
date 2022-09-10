// 496. Next Greater Element I
// Easy

// 4230

// 259

// Add to List

// Share
// The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

// You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

// For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

// Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.



// Example 1:

// Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
// Output: [-1,3,-1]
// Explanation: The next greater element for each value of nums1 is as follows:
// - 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
// - 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
// - 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
// Example 2:

// Input: nums1 = [2,4], nums2 = [1,2,3,4]
// Output: [3,-1]
// Explanation: The next greater element for each value of nums1 is as follows:
// - 2 is underlined in nums2 = [1,2,3,4]. The next greater element is 3.
// - 4 is underlined in nums2 = [1,2,3,4]. There is no next greater element, so the answer is -1.


// Constraints:

// 1 <= nums1.length <= nums2.length <= 1000
// 0 <= nums1[i], nums2[i] <= 104
// All integers in nums1 and nums2 are unique.
// All the integers of nums1 also appear in nums2.


// Follow up: Could you find an O(nums1.length + nums2.length) solution?

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> ans;
        for (int i = 0; i < nums1.size();i++)
        {
            for (int j = 0; j < nums2.size();j++)
            {
                if(nums1[i] == nums2[j])
                {
                    int max_val = -1;
                    for (int k = j; k < nums2.size();k++)
                    {
                        if(nums2[k] > nums2[j])
                        {
                            max_val = nums2[k];
                            break;
                        }
                    }
                    ans.push_back(max_val);
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {

        // since there are no duplicates we can store them in a map

        // ans to be returned, initialize with -1

        vector<int> ans(nums1.size(),-1);
        stack<int> stk;
        unordered_map<int, int> mp;
        for (int i = 0; i < nums2.size();i++)
        {
            int element = nums2[i];
            while(!stk.empty() && element > stk.top())
            {

                // next greater element of st.top() is element

                mp[stk.top()] = element;
                stk.pop();
            }
            stk.push(element);
        }

        // inserting the found next greater elements into the ans

        for (int i = 0; i < nums1.size();i++)
        {
            int ele = nums1[i];
            if(mp.find(ele) != mp.end())
            {
                int NGE = mp[ele];
                ans[i] = NGE;
            }
        }
        return ans;
    }
};