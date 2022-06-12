class Solution {
public:
    int maxArea(vector<int>& height) 
    {

        // if the value of first index is less than the value of last index increase the first index else decrease the last index

        int n = height.size();
        int area = 0;
        int l = 0;
        int r = n-1;
        while(l < r)
        {

            // area formula will be maximum of max_area and min(array[first] , array[last])*(last-first)

            area = max(area,min(height[l],height[r]) * (r-l));
            if(height[l] < height[r])
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        return area;
    }
};