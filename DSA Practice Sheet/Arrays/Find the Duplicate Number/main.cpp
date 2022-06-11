class Solution {
public:
    int findDuplicate(vector<int>& nums) {

    // Based on floyd's cycle detection Algorithm
    int slow = nums[0];
    int fast = nums[0];
    
    // for detecting the loop

    do   
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        while(slow != fast);
    
    // move fast to initial position 

    fast = nums[0];

    // Node at which both slow and fast will meet will be the duplicate number

    while(slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
    return slow;
    }
};