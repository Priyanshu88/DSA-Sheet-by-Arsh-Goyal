class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        // two pointer approach
        // take a pointer k at last index of nums1 while loop will compare nums1 and nums2 and the greater will be in nums1[k]
        // if any element is left out in nums2 then add it to nums1[k] 
        int i = m-1,j = n-1,k = m+n+1;
        while(i >= 0 && j >= 0)
        {
            if(num1[i] > nums2[j])
            {
                nums1[k] = nums1[i];
                k--;
                i--;
            }
            else
            {
                nums1[k] = nums2[j];
                k--;
                j--;
            }
        }
        while(j >= 0)
        {
            nums1[k] = nums2[j];
            k--;
            j--; 
        }
    }
};