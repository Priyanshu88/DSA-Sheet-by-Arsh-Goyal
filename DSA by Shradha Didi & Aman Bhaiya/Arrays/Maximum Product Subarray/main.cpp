// 152. Maximum Product Subarray

// Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product, and return the product.

// The test cases are generated so that the answer will fit in a 32-bit integer.

// A subarray is a contiguous subsequence of the array.

// Example 1:

// Input: nums = [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6.
// Example 2:

// Input: nums = [-2,0,-1]
// Output: 0
// Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

// Constraints:

// 1 <= nums.length <= 2 * 104
// -10 <= nums[i] <= 10
// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        // empty array case
        if (nums.size() == 0)
            return 0;

        // maxSub and minSub will hold the products till nums[i]
        int maxSub = nums[0];
        int minSub = nums[0];
        int maxProductSub = nums[0];

        for (size_t i = 1; i < nums.size(); i++)
        {
            // element is negative so we swap max and min
            // because when multiplying negative with a negative, number becomes positive so minimum negative number will become the maximum number
            if (nums[i] < 0)
                swap(minSub, maxSub);

            // update all the sub values
            maxSub = max(maxSub * nums[i], nums[i]);
            minSub = min(minSub * nums[i], nums[i]);
            // choose max product to be the max between the maxProduct till now and maxSub
            maxProductSub = max(maxProductSub, maxSub);
        }

        return maxProductSub;
    }
};

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size(), res = nums[0], l = 1, r = 1;
        for (int i = 0; i < n; i++)
        {
            l = (l)*nums[i];
            r = (r)*nums[n - 1 - i];
            res = max(res, max(l, r));
            if (l == 0)
                l = 1;
            if (r == 0)
                r = 1;
        }
        return res;
    }
};