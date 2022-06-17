class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        // boyer moore voting algo
        // initialize count variable to count the occurrence and majority variable to keep track of element which is being count

        int majority,count = 0;
        for(int i=0;i<nums.size();i++)
        {

            // if count is 0 then assign current element to majority variable

            if(count == 0)
            {
                majority = nums[i];
            }

            // if nums[i] is equal to majority increase the count else decrease

            if(majority == nums[i])
            count++;
            else
            count--;
        }

        // return majority

        return majority;
    }
};