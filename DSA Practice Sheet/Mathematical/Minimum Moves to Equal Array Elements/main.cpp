class Solution {
public:

    // Sorting the array then taking the minimum number from the sorted array
    // Traversing the vector from right and subtracting the minimum number from all the elements in the array
    // The summation of the difference taken is the required answer.

    int minMoves(vector<int>& nums) 
    {
        int answer = 0;
        sort(nums.begin(),nums.end());
        int min_num = nums[0];

        for(int i=nums.size()-1;i>=0;i--)
        {
            answer += (nums[i] - min_num);
        }
        return answer;
    }
};



class Solution {
public:


    int minMoves(vector<int>& nums) 
    {
        int m = INT_MAX;
        for(int n:nums) m = min(m,n);
        int ans = 0;
        for(int n:nums) ans+=n-m;
        return ans;
    }
};
