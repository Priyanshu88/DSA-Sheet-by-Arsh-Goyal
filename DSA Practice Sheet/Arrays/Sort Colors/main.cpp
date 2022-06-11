class Solution {
public:
    void sortColors(vector<int>& nums) {
    int n = nums.size();
    int low = 0;
    int high = n-1;
    int mid = 0;

    // Iterate until mid is less than high    

    while(mid <= high)
    {

        // Every element before low is 0 and increment both low and mid 

        if(nums[mid] == 0)
        {
            swap(nums[low++],nums[mid++]);
        }
        else if(nums[mid] == 1)
        {
            mid++;
        }

        // Every element after high is 2 Decrement high pointer

        else
        {
            swap(nums[high--],nums[mid]);
        }
    }
    }
};