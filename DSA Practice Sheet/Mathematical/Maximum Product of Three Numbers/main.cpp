class Solution {
public:
    int maximumProduct(vector<int>& nums) 
    {

        // if positive then sort the array and find out the product of the last three numbers
        // it will maximum for positive numbers 
        // for negative numbers lying at the left extreme end could also contribute to lead to a larger product as the -10 will be be before -4 so 
        // if the third number in the triplet being considered is the largest positive number in the nums array then the max product is possible

        int n = nums.size();
        sort(nums.begin(),nums.end());
        return max(nums[0]*nums[1]*nums[n-1],nums[n-3]*nums[n-2]*nums[n-1]);    
    }
};


// finding the required 2 smallest values(min_val1 and min_val2) and 
// the three largest values(max_val1, max_val2, max_val3)
// in the nums array, by iterating over the nums array only once
// again finding out the larger value out of min_val1 * min_val2 * max_val1
// and max_val1 * max_val2 * max_val3

class Solution {
public:
    int maximumProduct(vector<int>& nums) 
    {
        int min_val1 = INT_MAX;
        int min_val2 = INT_MAX;
        int max_val1 = INT_MIN;
        int max_val2 = INT_MIN;
        int max_val3 = INT_MIN;

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] <= min_val1)
            {
                min_val2 = min_val1;
                min_val1 = nums[i];
            }

            else if(nums[i] <= min_val2)
            {
                min_val2 = nums[i];
            }
            if(nums[i] >= max_val1)
            {
                max_val3 = max_val2;
                max_val2 = max_val1;
                max_val1 = nums[i];
            }
            else if(nums[i] >= max_val2)
            {
                max_val3 = max_val2;
                max_val2 = nums[i];
            }
            else if(nums[i] >= max_val3)
            {
                max_val3 = nums[i];
            }
            
        }

        return max(min_val1*min_val2*max_val1, max_val1*max_val2*max_val3);
    }
};