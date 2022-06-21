class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        int n = heights.size();
        if(n == 0) return 0;
        int maxArea = 0;
        vector<int> left(n); //
        vector<int> right(n);

        left[0] = -1;
        right[n-1] = n;

        for(int i=1;i<n;i++)
        {
            int prev = i-1;
            while(prev >= 0 && heights[prev] >= heights[i])
            {
                prev = left[prev];
            }
            left[i] = prev;
        }

        for(int i=n-2;i>=0;i--)
        {
            int next = i+1;
            while(next < n && heights[next] >= heights[i])
            {
                next = right[next];
            }
            right[i] = next;
        }

        for(int i=0;i<n;i++)
        {
            int width = right[i]-left[i]-1;
            maxArea = max(maxArea,heights[i]*width);
        }
        return maxArea;

    }
};


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        int n = heights.size();
        int maxArea = 0;
        stack<int> st;
        for(int i =0;i<=n;i++)
        {

            // if the currHeight is greater than height[top] we do push as it is increasing otherwise
            // pop the element and find the area

            int currHeight = i == n ? 0 : heights[i];
            while(!st.empty() && currHeight < heights[st.top()])
            {

                // current element on which we are working

                int top = st.top(); st.pop();
                
                // width differ if stack is empty or not empty after we pop the element

                int width = st.empty() ? i : i-st.top()-1;
                int area = heights[top]*width;
                maxArea = max(area,maxArea);
            }

            // keep on adding the indexes in the stack till we get a increasing sequence

            st.push(i);
        }
        return maxArea;
    }
};