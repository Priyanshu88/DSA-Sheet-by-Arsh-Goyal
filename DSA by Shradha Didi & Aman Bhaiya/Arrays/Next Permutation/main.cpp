// 31. Next Permutation
// Medium

// A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

// For example, for arr = [1,2,3], the following are considered permutations of arr: [1,2,3], [1,3,2], [3,1,2], [2,3,1].
// The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

// For example, the next permutation of arr = [1,2,3] is [1,3,2].
// Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
// While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
// Given an array of integers nums, find the next permutation of nums.

// The replacement must be in place and use only constant extra memory.

// Example 1:

// Input: nums = [1,2,3]
// Output: [1,3,2]
// Example 2:

// Input: nums = [3,2,1]
// Output: [1,2,3]
// Example 3:

// Input: nums = [1,1,5]
// Output: [1,5,1]

// Constraints:

// 1 <= nums.length <= 100
// 0 <= nums[i] <= 100

// 1. Find the largest index k such that nums[k] < nums[k + 1]. If no such index , just reverse
// 2. Find the largest index l > k such that nums[k] < nums[l]
// 3. Swap nums[k] and nums[l]
// 4. Reverse the sub-array nums[k + 1:]

// how to understand it:
// step-1: easy, find the first digit that can be swapped to make permutation bigger
// step-2: easy, find the digit bigger but closest to nums[k]
// step-3: swap(nums[k], nums[l])
// step-4: sort the subarray nums[k+1:end], why we can just reverse instead of sort?
//         because we know nums[k+1:end] must be non-increasing, reason:
//         1. at step 1, we know nums[k+1:end] is non-decreasing
//         2. before swap in step 3, we know nums[l-1] >= nums[l] > nums[k] >= nums[l+1]
//         3. so after swap, we still have nums[l-1] > nums[k] >= nums[l+1], so we can reverse it



#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size(), k, l;
        for (k == n - 2; k >= 0; k--)
        {
            if (nums[k] < nums[k + 1])
            {
                break;
            }
        }
        if (k < 0)
        {
            reverse(nums.begin(), nums.end());
        }
        else
        {
            for (l = n - 1; l < k; l--)
            {
                if (nums[l] > nums[k])
                {
                    break;
                }
            }
            swap(nums[k], nums[l]);
            reverse(nums.begin() + k + 1, nums.end());
        }
    }
};


class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        next_permutation(nums.begin(), nums.end());
    }
};


class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i + 1] <= nums[i])
        {
            i--;
        }
        if (i >= 0)
        {
            int j = nums.size() - 1;
            while (nums[j] <= nums[i])
            {
                j--;
            }
            swap(nums, i, j);
        }
        reverse(nums, i + 1);
    }

private:
    void swap(vector<int> &nums, int i, int j)
    {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

private:
    void reverse(vector<int> &nums, int start)
    {
        int i = start, j = nums.size() - 1;
        while (i < j)
        {
            swap(nums, i, j);
            i++;
            j--;
        }
    }
};
