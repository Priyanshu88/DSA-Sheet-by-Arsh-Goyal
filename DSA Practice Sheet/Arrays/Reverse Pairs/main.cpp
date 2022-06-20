class Solution {
public:
    int ans;

    // merge function for merge sort

    void merge(vector<int>&nums,int l,int m,int r)
    {
        int n1 = m-l+1; int n2 = r-m;
        int left[n1]; int right[n2];
        for(int i=0;i<n1;i++)
        {
            left[i] = nums[l+i];
        } 
        for(int i=0;i<n2;i++)
        {
            right[i] = nums[m+1+i];
        }
        int i=0,j=0;

        // checking the provided condition for reverse pair

        while(i<n1 && j<n2)
        {
            if(left[i]/(2.0) > right[j])
            {
                ans += n1-i;
                j++;
            }
            else
            i++;
        }
        i=0,j=0; int k = l;
        while(i<n1 && j<n2)
        {
            if(left[i] <= right[j])
            nums[k++] = left[i++];
            else
            nums[k++] = right[j++];
        }
        while(i<n1)
        nums[k++] = left[i++];
        while(j<n2)
        nums[k++] = right[j++];
        
    }

    // perform merge sort

    void MergeSort(vector<int>&nums,int l,int r)
    {
        if(r>l)
        {
            int mid = l+(r-l)/2;
            MergeSort(nums,l,mid);
            MergeSort(nums,mid+1,r);
            merge(nums,l,mid,r);
        }
    }

    // implement the functions

    int reversePairs(vector<int>& nums) 
    {
        ans = 0;
        MergeSort(nums,0,nums.size()-1);
        return ans;
    }
};