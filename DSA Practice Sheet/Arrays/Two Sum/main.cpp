class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> mp;
    for (int i=0;i<nums.size();i++)
    {   

        // iterate and insert element into hashtable look back to check the difference with
        // current elements already exists in hash

        int diff = target - nums[i];
        if(mp.count(diff))
        { 

            // return indices

            return {mp[diff],i};
        }
            mp[nums[i]] = i;
    }

    // or return null 

        return {};
    }
};