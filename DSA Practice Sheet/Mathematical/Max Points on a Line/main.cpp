class Solution {
    public:
    
    int maxPoints(vector<vector<int>>& points) 
    { 
        int n = points.size();
        if(n <= 2) return n;
        int res = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int x1 = points[i][0];
                int x2 = points[j][0];
                int y1 = points[i][1];
                int y2 = points[j][1];

                // double slope = double(y2-y1)/double(x2-x1);

                int total = 2;

                for(int k=0;k<n && k != i && k != j;k++)
                {
                    int x = points[k][0];
                    int y = points[k][1];

                    if((y2 - y1)*(x - x1) == (x2 - x1)*(y - y1))
                    {
                        total++;
                    }
                }
                res = max(res,total);
            }
        }
        return res;
    }
};











class Solution {
public:

    // if slopes of arbitrary two pairs are the same
    // then points are on the same line
    // so for a point, calculating all slopes between point and other points. so the cases are:
    // Some other point is the same as point
    // Some other point has the same x coordinate as the point, which will result to a positive infinite slope
    // and for general case, calculating slope
    // storing all slopes in a hash and finding which slope shows up mostly then adding the number of same points to it. 
    // Then we know the maximum number of points on the same line for point
    // doing the same thing to other points
    // Finally, just returning the maximum result among all other points

    int maxPoints(vector<vector<int>>& points) 
    {
        int result = 0;
        for(int i=0;i<points.size();i++)
        {
            unordered_map<long double,int> hash;
            int same = 1;
            int localmax = 0;
            for(int j = i+1;j<points.size();j++)
            {
                if(points[i][0] == points[j][0] && points[i][1] == points[j][1])
                {
                    same++;
                }
                else if(points[i][0] == points[j][0])
                {
                    hash{INT_MAX}++;
                }
                else 
                {
                    long double slope = (long double) (points[i][1] - points[j][1])/(long double) (points[i][0] - points[j][0]);
                    hash[slope]++;
                }

            }
            for(auto i: hash)
            {
                localmax = max(localmax,i.second);
            }
            localmax += same;
            result = max(result,localmax);
        }
        return result;

    }
};