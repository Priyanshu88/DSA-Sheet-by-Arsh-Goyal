class Solution {
public:

    vector<int>res;    
    void MergeSort(vector<int>&nums, int left, int right, vector<int>&tmp, vector<int>& index)
    {
        if(left >= right) return;
        int mid = left+(right-left)/2;
        MergeSort(nums, left, mid, tmp, index);
        MergeSort(nums,mid+1,right,tmp,index);
        int i = left;
        int j = mid+1;
        int k = left;
        int count = 0;
        while(i <= mid)
        {
            while(j <= right && nums[index[j]] < nums[index[i]])
            {
                count++;
                tmp[k++] = index[j++];
            }

            res[index[i]] += count;
            tmp[k++] = index[i++];
        }

        while (j <= right)
        {
            tmp[k++] = index[j++]; 
        }
        

        for(int i=1;i<=right;i++)
        {
            index[i] = tmp[i];
        }
        

    }

    vector<int> countSmaller(vector<int>& nums) 
    {
        res.resize(nums.size());
        vector<int> tmp(nums.size(),0);
        vector<int> index;
        for(int i=0;i<nums.size();i++)
        {
            index.push_back(i);
        }

        MergeSort(nums,0,nums.size()-1,tmp,index);
        return res;
    }
};

// T.C.:O(n log n)
// S.C.:O(n)




class Solution {


    int *bit, len = 20001, offset = 10001;
    void updateBit(int n)
    {
        while (n < len)
        {
            // Add 1 to current node of bit
            
            bit[n]++;

            // update index to that of parent in update

            n += n & (-n);
        }
        
    }

    int getValueFromBit(int n)
    {
        int res = 0;
        while(n > 0)
        {
            res += bit[n];
            n -= n&(-n);
        }
        return res;
    }

public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res(nums.size());
        bit = new bit[len];
        fill(bit,bit+len,0);
        for(int i=nums.size()-1,n;i>=0;i--)
        {
            n = nums[i] + offset;
            res[i] = getValueFromBit(n-1);
            updateBit(n);
        }
        return res;
    }
};

