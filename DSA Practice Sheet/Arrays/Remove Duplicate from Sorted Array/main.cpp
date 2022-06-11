class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

    // two pointer

    // Edge case

    if(nums.size() == 0)
    {
        return 0;
    }

    // i will iterate over all elements & j will be the index of duplicates numbers

    int i=0;
    for (int j = 1;j<nums.size();j++)
    {
        if(nums[i] != nums[j])
        {

            // replace j only if we find a number not similar to the j-indexed number

            i++;
            nums[i] = nums[j];
        }
    }
        return i+1;
    }
};