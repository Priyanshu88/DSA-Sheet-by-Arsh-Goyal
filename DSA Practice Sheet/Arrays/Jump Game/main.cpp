class Solution {
public:
    bool canJump(vector<int>& nums) 
    {

        // what is the maximum index that we can reach from every index
        // if maximum index reached is the last index of array
        // if same return true otherwise false

        int reachable = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(reachable < i)
            return false;
            reachable = max(reachable,i+nums[i]);
        }    
        return true;   
    }
};