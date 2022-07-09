class Solution {
public:
    int maximumProduct(vector<int>& nums) 
    {
        for(int i=0;i<nums.size();i++)
        {
            int ans += nums[i]*nums[i+1];
        }
        return ans;
    }
};