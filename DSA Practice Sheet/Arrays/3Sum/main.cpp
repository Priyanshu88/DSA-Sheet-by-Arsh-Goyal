class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {

        // two pointer approach

        // If array size is < 3 and if first element is +ve return empty vector

        sort(nums.begin(),nums.end());
        if(nums.size() < 3)
        {
            return {};
        }
        if(nums[0] > 0)
        {
            return {};
        }
        vector<vector<int>> ans;
        for (int i = 0;i<nums.size();i++)
        {

            // If number fixed is +ve,

            if(nums[i] > 0)
            {
                break;
            }

            // if number is getting repeated, ignore the lower loop and continue

            if(i>0 && nums[i] == nums[i-1])
            {
                continue;
            }
            int l = i+1;
            int r = nums.size()-1;
            int sum = 0;
            while(l < r)
            {
                sum = nums[i] + nums[l] + nums[r];

                // If sum is -ve them l++

                if(sum < 0)
                {
                    l++;
                }

                // If sum is +ve them r--

                else if(sum > 0)
                {
                    r--;
                }

                // found the required triplet, push it in vector

                else
                {
                    ans.push_back({nums[i],nums[l],nums[r]});
                    
                    // to avoid duplicate triplets
                    // Update the l and r with last occurences of l and r

                    int prevl = nums[l];
                    int prevr = nums[r];
                    while(l<r && nums[l] == prevl)
                    {
                        l++;
                    }
                    while(l<r && nums[l] == prevr)
                    {
                        r--;
                    }
                }
            }
        }
        return ans;
    }
};