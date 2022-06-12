class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        int n = nums.size();
        int prefix[n];
        prefix[0] = nums[0];
        // calculating prefix sum
        for(int i=1;i<n;i++)
        {
            prefix[i] = nums[i] + prefix[i-1];
        }

        unordered_map<int,int> mp;
        int ans = 0;
        for(int i=0;i<n;i++)
        {

            // if it prefix[i] is equal to k increment answer

            if(prefix[i] == k)
            {
                ans++;
            }

            // if (prefix[i] - k) is present add it in our answer and put prefix sum in our map

            if(mp.find(prefix[i]-k) != mp.end())
            {
                ans += mp[prefix[i]-k];
            }
            mp[prefix[i]]++;
        }
        return ans;
    }
};