class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        vector<vector<int>> ans;
        
        // base case
        
        if(nums.empty())
        {
            return ans;
        }
    
        int n = nums.size();
        
        // sorting the array

        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            for(int j = i+1;j<n;j++)
            {
                
                // our second target element/sum

                int target_2 = target - nums[j] - nums[i];
                int front = j+1;
                int back = n-1;

                // front pointer after j and back pointer before n

                while(front < back)
                {

                    // if desired is equal to two_sum store the quadruplet

                    int two_sum = nums[front] + nums[back];
                    if(two_sum < target_2) front++;
                    else if(two_sum > target_2) back--;
                    else
                    {
                        vector<int> quadruplet(4,0);
                        quadruplet[0] = nums[i];
                        quadruplet[1] = nums[j];
                        quadruplet[2] = nums[front];
                        quadruplet[3] = nums[back];
                        ans.push_back(quadruplet);

                        // if the previous element of front index is same as quadruple[2] increment front

                        while(front < back && nums[front] == quadruplet[2]) front++;

                        // if the previous element of back index is same as quadruple[3] decrement back

                        
                        while(front < back && nums[back] == quadruplet[3]) back--;

                    }
                }

                // if the next element of jth index is same as jth index increment j

                while (j+1 < n && nums[j+1] == nums[j]) j++;

            }

            // if the next element of ith index is same as ith index increment i

            while(i+1 < n && nums[i+1] == nums[i]) i++;
        }
        return ans;
    }
};