class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) 
    {
        int curr_max = 0;
        
        // iterating through the first k cards and finding the curr_max
        
        for(int i=0;i<k;i++)
        {
            curr_max += cardPoints[i];
        }

        // assign curr_max to maxPoint for further check

        int maxPoint = curr_max;
        
        // for reverse window cards i=k to j=cardPoint.size()-1, each iteration we will slide the window 
        //backwards removing one card from left and adding one card from right
        
        for(int i=k-1,j=cardPoints.size()-1;i>=0;i--,j--)
        {
            curr_max += cardPoints[j] - cardPoints[i];

            // keep track of maximum

            maxPoint = max(maxPoint,curr_max);
        }
        return maxPoint;
    }
};