class Solution {
public:

// we make use of the fact that two consecutive numbers nums[j]
// and nums[j+1] are never equal. Thus, we can traverse over the
// nums array starting from the beginning. Whenever, we find a number nums[i],
// we only need to check if it is larger than the next number nums[i+1]
// for determining if nums[i] is the peak element.

// All the numbers appear in a descending order. In this case, the first element
// corresponds to the peak element. We start off by checking if the current element
// is larger than the next one. The first element satisfies this criteria, and is hence 
// identified as the peak correctly


    int findPeakElement(vector<int>& nums) 
    {
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] >= nums[i+1])
            return i;
        }
        return nums.size()-1;
    }
};

// T.C.:O(n)
// S.C.:O(1)



class Solution {
public:
    int findPeakElement(vector<int>& nums) 
    {
        int left = 0;
        int right = nums.size()-1;
        while(left < right)
        {
            int mid = (left+right)/2;
            if(nums[mid] > nums[mid+1])
            {
                r = mid;
            }
            else 
            {
                l = mid+1; 
            }
        }
        return left;
    }
};