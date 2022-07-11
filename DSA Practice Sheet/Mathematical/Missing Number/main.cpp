class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> arr(n+1,-1);
        int ans;

        for(int i=0;i<n;i++)
        {
            arr[nums[i]] = nums[i];
        }

        for(int i=0;i<n;i++)
        {
            if(arr[i] == -1)
            {
                ans  = i;
                break;
            }
        }
        return ans;
    }
};



class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {

        // finding the sum of n natural number of range nad 
        // then taking the difference of sum form total, that will be the exact missing number 

        int sum = 0;

        // calculating the sum of ranged element

        int total = nums.size()*(nums.size()+1)/2;

        // iterating the loop

        for(auto num:nums)
        {

            // adding the nums

            sum += num;
        }

        // difference of sum from total

        return total-sum;
    }
};