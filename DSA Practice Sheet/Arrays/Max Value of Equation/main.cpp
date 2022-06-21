class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) 
    {
        priority_queue<pair<int,int>> pq;
        int ret = INT_MIN;
        for(auto point:points)
        {
            while(pq.size() && point[0]-pq.top().second > k)
            pq.pop();
            if(!pq.empty())
            ret = max(ret,point[0]+point[1]+pq.top().first);
            pq.push(make_pair(point[1]-point[0],point[0]));
        }
        return ret;
    }
};



class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) 
    {

        // decreasing deque to find the max of yi-xi for every j(i<j)


        deque<vector<int>> dq;
        
        // push the points in this format for easy lookup (xi,yi-xi)

        dq.push_back({points[0][0],points[0][1]-points[0][0]});
        int n = points.size();
        int maxVal = INT_MIN;

        for(int j=1;j<n;j++)
        {

            // pop all those points from front which are out of k distance from j point as all points in deque are also in ascending order with respect to x


            while(!dq.empty() && points[j][0]-dq.front()[0] > k)
            dq.pop_front();
            if(!dq.empty())
            {

                // front point has max (yi-xi)

                int val = dq.front()[1]+points[j][1]+points[j][0];
                maxVal = max(maxVal,val);
            }

            int v = points[j][1]-points[j][0];
            
            // pop all the points which have less yi-xi values

            while(!dq.empty() && dq.back()[1]<=v)

            dq.pop_back();

            // push the point in deque
            
            dq.push_back({points[j][0],v});
        }
        return  maxVal;
    }
};


// We can use the sliding window technique and monotonically decreasing deque d. The maximum yi - xi therefore will be in the front. For the deque, we can just store the index j there to make it faster.

// First, remove items that got out of the xj - xi window from the front of the queue. Then, we compute our value. Finally, we add i to the deque, making sure we keep monotonicity of y - x. In other words, we just remove all elements with smaller y - x from the back of the deque.

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k)     {
        int res= INT_MIN;
        deque<int> dq;
        for (int j=0;j<points.size();j++)
        {
            while(!dq.empty() && points[j][0]-points[dq.front()][0] > k)
                dq.pop_front();
            if(!dq.empty())
                res = max(res,points[dq.front()][1]-points[dq.front()][0]+points[j][1]+points[j][0]);
            while(!dq.empty() && points[dq.back()][1]-points[dq.back()][0] < points[j][1] - points[j][0])
                dq.pop_back();
            dq.push_back(j);
        }
        return res;
    }
};