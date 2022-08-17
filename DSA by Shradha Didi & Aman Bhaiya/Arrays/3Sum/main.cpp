// 15. 3Sum

// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

// Notice that the solution set must not contain duplicate triplets.

// Example 1:

// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
// Explanation:
// nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
// nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
// nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
// The distinct triplets are [-1,0,1] and [-1,-1,2].
// Notice that the order of the output and the order of the triplets does not matter.
// Example 2:

// Input: nums = [0,1,1]
// Output: []
// Explanation: The only possible triplet does not sum up to 0.
// Example 3:

// Input: nums = [0,0,0]
// Output: [[0,0,0]]
// Explanation: The only possible triplet sums up to 0.

// Constraints:

// 3 <= nums.length <= 3000
// -105 <= nums[i] <= 105

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;
        if (nums.size() == 0 || nums.size() < 3)
            return {};

        // sorting

        sort(nums.begin(), nums.end());

        // iterating till second last element

        for (int i = 0; i < nums.size() - 2; i++)
        {

            // if i is 0 or i is greater than 0 and previous element is not same as next element

            if (i == 0 || (i > 0 && nums[i - 1] != nums[i]))
            {

                // initializing low to i+1

                int low = i + 1;

                // high to size-1

                int high = nums.size() - 1;

                // and sum as -(element)
                int sum = 0 - nums[i];
                while (low < high)
                {
                    if (sum == nums[low] + nums[high])
                    {
                        result.push_back({nums[i], nums[low], nums[high]});
                        while (low < high && nums[low] == nums[low + 1])
                            low++;
                        while (low < high && nums[high] == nums[high - 1])
                            high--;
                        low++;
                        high--;
                    }
                    else if (sum > nums[low] + nums[high])
                    {
                        low++;
                    }
                    else
                    {
                        high--;
                    }
                }
            }
        }
        return result;
    }
};

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        if (nums.size() < 3)
        {
            return {};
        }
        if (nums[0] > 0)
        {
            return {};
        }
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            int l = i + 1;
            int r = nums.size() - 1;
            int sum = 0;
            while (l < r)
            {
                sum = nums[i] + nums[l] + nums[r];
                if (sum < 0)
                {
                    l++;
                }
                else if (sum > 0)
                {
                    r--;
                }
                else
                {

                    ans.push_back({nums[i], nums[l], nums[r]});
                    int prevl = nums[l];
                    int prevr = nums[r];
                    while (l < r && nums[l] == prevl)
                    {
                        l++;
                    }
                    while (l < r && nums[l] == prevr)
                    {
                        r--;
                    }
                }
            }
        }
        return ans;
    }
};
