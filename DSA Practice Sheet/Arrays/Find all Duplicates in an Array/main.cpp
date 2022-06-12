class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) 
    {
        vector<int> ans;

        // Negating the value at index of ((absolute value of scanned element) - 1))

        for(auto i:nums)
        {
            i = abs(i);

            // if the value of the index is +ve it's duplicate

            if(nums[i-1] > 0)
            {
                nums[i-1] *= -1;
            }
            else
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};