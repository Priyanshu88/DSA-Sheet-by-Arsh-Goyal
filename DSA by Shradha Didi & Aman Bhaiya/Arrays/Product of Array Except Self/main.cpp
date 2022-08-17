// 238. Product of Array Except Self

// Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

// You must write an algorithm that runs in O(n) time and without using the division operation.

// Example 1:

// Input: nums = [1,2,3,4]
// Output: [24,12,8,6]
// Example 2:

// Input: nums = [-1,1,0,-3,3]
// Output: [0,0,9,0,0]

// Constraints:

// 2 <= nums.length <= 105
// -30 <= nums[i] <= 30
// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

// Follow up: Can you solve the problem in O(1) extra space complexity? (The output array does not count as extra space for space complexity analysis.)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, 1);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;
                ans[i] = ans[i] * nums[j];
            }
        }
        return ans;
    }
};


class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n);
        vector<int> left_product(n);
        vector<int> right_product(n);

        left_product[0] = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            left_product[i] = left_product[i - 1] * nums[i - 1];
        }
        right_product[n - 1] = 1;
        for (int j = n - 2; j >= 0; j--)
        {
            right_product[j] = right_product[j + 1] * nums[j + 1];
        }
        for (int k = 0; k < n; k++)
        {
            ans[k] = left_product[k] * right_product[k];
        }
        return ans;
    }
};

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int len = nums.size();
        vector<int> answer(len);
        answer[0] = 1;
        for (int i = 1; i < len; i++)
        {
            answer[i] = nums[i - 1] * answer[i - 1];
        }
        int right = 1;
        for (int i = len - 1; i >= 0; i--)
        {
            answer[i] = answer[i] * right;
            right = right * nums[i];
        }
        return answer;
    }
};