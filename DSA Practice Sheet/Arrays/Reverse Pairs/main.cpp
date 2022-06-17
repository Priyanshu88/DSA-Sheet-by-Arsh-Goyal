class Solution {
private:
    int ans = 0;
    void merge(vector<int>&nums,int l,int m,int r)
    {
        int i=l,j=m+1;
        vector<int> temp;
        while(i<=m && j<= r)
        {
            if(nums[i] < nums[j])
            temp.push_back(nums[i++]);
            else
            temp.push_back(nums[j++]);
        }
        while (i<=m)
        {
            temp.push_back(arr[i++]);
        }
        while (j<=r)
        {
            temp.push_back(arr[j++]);
        }
        i=0;
        for(int x = l;x<=r;x++)
        nums[x] = temp[i++];
        
    }

    void MergeSort(vector<int>&nums,int l,int r)
    {
        if(l<r)
        {
            // dividing array in two parts recursively
            int i,j;
            int mid = (l+r)/2;
            MergeSort(arr,l,mid);
            MergeSort(arr,mid+1,r);
            j=mid+1;
            long long temp;
            for(int i=1;i<=mid;i++)
            {
                while(j<=r && (long)nums[i] >(long)2*nums[j])
                j++;
                ans+=j-mid-1;
            }
            merge(nums,l,mid,r);
        }
    }

public:

    int reversePairs(vector<int>& nums) 
    {
        MergeSort(nums,0,nums.size()-1);
        return ans;
    }
};