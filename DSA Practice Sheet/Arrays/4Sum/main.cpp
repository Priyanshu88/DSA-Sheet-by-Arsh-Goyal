class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        vector<vector<int>> ans;
        if(nums.empty())
        {
            return ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            for(int j = i+1;j<n;j++)
            {
                int target_2 = target - nums[j] - nums[i];
                int front = i+1;
                int back = n-1;
                while(front < back)
                {
                    int two_sum = nums[front] + nums[back];
                    if(two_sum < target) front++;
                    else if(two_sum > target) back--;
                    else
                    {
                        vector<int> quadruplet(4,0);
                        quadruplet[0] = nums[i];
                        quadruplet[1] = nums[j];
                        quadruplet[2] = nums[front];
                        quadruplet[3] = nums[back];
                        ans.push_back(quadruplet);
                        while(front < back && nums[fornt] == quadruplet[2]) front++;
                        
                        while(front < back && nums[back] == quadruplet[3]) back--;

                    }
                }
                while (j+1 < n && )
            }
        }
    }
};