class Solution {
public:

    int isPossible_subarray(vector<int>&nums,int max_sum_allowed)
    {
        int n = nums.size();
        int curr_sum = 0;
        int splits = 0;
        for(int i=0;i<n;i++)
        {

            // adding element only if the sum doesn't exceed max_sum_allowed

            if(curr_sum+nums[i] <= max_sum_allowed)
            {
                curr_sum += nums[i];
            }
            else
            {

                // If the element addition makes sum more than max_sum_allowed
                // incrementing the splits required and reset sum

                curr_sum = nums[i];
                splits++;
            }
        }

        // returning the number of subarrays, which is the number of splits + 1

        return splits+1;
    }


    int splitArray(vector<int>& nums, int m) {
        int left = 0;
        int right = 0;
        int min_lar_sum = 0;
        int n = nums.size();

        // finding the sum of all elements and the maximum element
        // defining the left and right boundary of binary search

        for(int i=0;i<n;i++) left = max(left,nums[i]), right += nums[i];
        while(left <= right)
        {

            // finding the mid value

            int max_sum_allowed = left + (right - left)/2;

            int count = isPossible_subarray(nums, max_sum_allowed);

            // finding the minimum splits. if count is less than
            // or equal to m move towards left i.e., smaller values

            if(count <= m)
            {
                
                right = max_sum_allowed-1;
                min_lar_sum = max_sum_allowed;
            }

             // else moving towards right if count is more than m

            else 
            {
                left = max_sum_allowed+1;
            }

        }
        return min_lar_sum;
    }
};