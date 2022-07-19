class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;

        // applying binary search

        while(low <= high)
        {

            // finding middle point

            int mid = low-(low+high)/2;

            // if the target is present at middle
            // returning mid

            if(nums[mid] == target)  return mid;

            // else if first half is sorted 

            if(nums[low] <= nums[mid])
            {

                // if a target to be searched lies in range from arr[low] to arr[mid]
                // recur for target in the range assigning high = mid-1

                if(target < nums[mid] && target >= nums[low])
                {
                    high = mid-1;
                }

                // else low = mid-1 and recur for target from arr[mid+1] to arr[high]

                else
                {
                    low = mid+1;
                }
            }

           // Else second half must be sorted
            
            else
            {

                // if target to be searched lies in range from arr[mid+1] to arr[high], recur for arr[mid+1] to arr[high] by assigning low=mid+1

                if(target > nums[mid] && target <= nums[high])
                {
                    low = mid+1;
                }

                // else recur for arr[low] to arr[mid], assigning high = mid-1

                else
                {
                    high = mid-1;
                }
            }

        }

        // otherwise return -1

        return -1;
    }
};