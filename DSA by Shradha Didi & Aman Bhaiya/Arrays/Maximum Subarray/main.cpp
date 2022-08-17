// Maximum Subarray
// Medium

// Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

// A subarray is a contiguous part of an array.

// Example 1:

// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6
// Explanation: [4,-1,2,1] has the largest sum = 6.
// Example 2:

// Input: nums = [1]
// Output: 1
// Example 3:

// Input: nums = [5,4,-1,7,8]
// Output: 23

// Constraints:

// 1 <= nums.length <= 105
// -104 <= nums[i] <= 104

// Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

// Method 1

#include <bits/stdc++.h>
using namespace std;

int maximum_sum(int nums[], int n)
{
    int max_sum = INT_MIN;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += nums[j];
            if (sum > max_sum)
            {
                max_sum = sum;
            }
        }
    }
    return max_sum;
}

// Method 2

int max(int x, int y)
{
    return (x > y) ? x : y;
}
int maximum_sum(int nums[], int low, int high)
{
    if (high <= low)
    {
        return nums[low];
    }

    int mid = (low + high) / 2;
    int left_max = INT_MIN;
    int sum = 0;
    for (int i = mid; i >= low; i--)
    {
        sum += nums[i];
        if (sum > left_max)
        {
            left_max = sum;
        }
    }

    int right_max = INT_MIN;
    sum = 0;
    for (int i = mid + 1; i <= high; i++)
    {
        sum += nums[i];
        if (sum > right_max)
        {
            right_max = sum;
        }
    }

    int max_left_right = max(maximum_sum(nums, low, mid), maximum_sum(nums, mid + 1, high));

    return max(max_left_right, left_max + right_max);
}

// Method 3

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int max_sum = nums[0], sum = nums[0];
        for (int i = 1; nums.size(); i++)
        {
            max_sum = max(nums[i], max_sum + nums[i]);
            sum = max(sum, max_sum);
        }
        return sum;
    }
};

// Method 4

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int Max = INT_MIN;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            Max = max(sum, Max);
            if (sum < 0)
                sum = 0;
        }
        return Max;
    }
};
