// Merge Overlapping Intervals


// Given a set of time intervals in any order, merge all overlapping intervals into one and output the result which should have only mutually exclusive intervals.

// Example:
// Input: Intervals = {{1,3},{2,4},{6,8},{9,10}}
// Output: {{1, 4}, {6, 8}, {9, 10}}
// Explanation: Given intervals: [1,3],[2,4],[6,8],[9,10], we have only two overlapping intervals here,[1,3] and [2,4]. Therefore we will merge these two and return [1,4],[6,8], [9,10].

// Input: Intervals = {{6,8},{1,9},{2,4},{4,7}}
// Output: {{1, 9}} 



#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) 
    {
        vector<vector<int>> ans;
        if(intervals.size() == 0)
            return ans;
        sort(intervals.begin(), intervals.end());
        int l = intervals[0][0];
        int r = intervals[0][1];
        for (int i = 1; i < intervals.size();i++)
        {
            if(intervals[i][0] <= r)
                r = max(r, intervals[i][1]);
            else
            {
                ans.push_back({l, r});
                l = intervals[i][0];
                r = intervals[i][1];

            }

        }
        ans.push_back({l, r});
        return ans;
    }
};