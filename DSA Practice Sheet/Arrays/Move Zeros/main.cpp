class Solution {
public:
    void moveZeroes(vector<int>& nums) {
    int count = 0;
    for (int i=0;i<nums.size();i++)
    {
        if(nums[i] != 0)
        {
            // if found non zero after  0 swap with the first appeared 0 determined by count
            
            swap(nums[i],nums[count]);
            count++;
        }
    }
    }
};