// Rotten Oranges
// MediumAccuracy: 50.57%Submissions: 46288Points: 4
// Lamp
// This problem is part of GFG SDE Sheet. Click here to view more.  

// Given a grid of dimension nxm where each cell in the grid can have values 0, 1 or 2 which has the following meaning:
// 0 : Empty cell
// 1 : Cells have fresh oranges
// 2 : Cells have rotten oranges

// We have to determine what is the minimum time required to rot all oranges. A rotten orange at index [i,j] can rot other fresh orange at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time. 
 

// Example 1:

// Input: grid = {{0,1,2},{0,1,2},{2,1,1}}
// Output: 1
// Explanation: The grid is-
// 0 1 2
// 0 1 2
// 2 1 1
// Oranges at positions (0,2), (1,2), (2,0)
// will rot oranges at (0,1), (1,1), (2,2) and 
// (2,1) in unit time.
// Example 2:

// Input: grid = {{2,2,0,1}}
// Output: -1
// Explanation: The grid is-
// 2 2 0 1
// Oranges at (0,0) and (0,1) can't rot orange at
// (0,3).
 

// Your Task:
// You don't need to read or print anything, Your task is to complete the function orangesRotting() which takes grid as input parameter and returns the minimum time to rot all the fresh oranges. If not possible returns -1.
 

// Expected Time Complexity: O(n*m)
// Expected Auxiliary Space: O(n)
 

// Constraints:
// 1 ≤ n, m ≤ 500

#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
        int orangesRotting(vector<vector<int>> &grid)
        {
            int n = grid.size();
            int m = grid[0].size();
            int time = -1;

            queue<pair<int, int>> q;
            int noOfFreshOranges = 0;
            int noOfRottenOranges = 0;
            for (int i = 0; i < n;i++)
            {
                for (int j = 0; j < m;j++)
                {
                    if(grid[i][j] == 2)
                    {
                        q.push({i, j});
                        grid[i][j] = -1;
                        noOfRottenOranges++;
                    }
                    else if(grid[i][j] == 1)
                    {
                        noOfFreshOranges++;
                    }
                }
            }
                if(noOfFreshOranges == 0) return 0;
                else if(noOfRottenOranges == 0 && noOfFreshOranges != 0) return -1;
                else if(noOfRottenOranges != 0 && noOfFreshOranges == 0) return 0;
                
                int orangeRottenLatter = 0;
                while(!q.empty())
                {
                    time++;
                    int size = q.size();
                    for (int p = 0; p < size;p++)
                    {
                        int i = q.front().first;
                        int j = q.front().second;

                        // up check

                        if(i-1 >= 0 and grid[i-1][j] == 1)
                        {
                            q.push({i - 1, j});
                            grid[i - 1][j] = -1;
                            orangeRottenLatter++;
                        }

                        // down

                        if(i+1 < n and grid[i+1][j] == 1)
                        {
                            q.push({i + 1, j});
                            grid[i + 1][j] = -1;
                            orangeRottenLatter++;
                        }

                        // left

                        if(j-1 >= 0 and grid[i][j-1] == 1)
                        {
                            q.push({i, j-1});
                            grid[i][j-1] = -1;
                            orangeRottenLatter++;
                        }
                        if(j+1 < m and grid[i][j+1] == 1)
                        {
                            q.push({i, j+1});
                            grid[i][j+1] = -1;
                            orangeRottenLatter++;
                        }
                        q.pop();
                    }
                }
                if(noOfFreshOranges != !orangeRottenLatter) return -1;
                return time;
            }
};



    bool isvalid(int x, int y, int row, int col){
        if(x<0 || y<0 || x>=row || y>=col) return false;
        return true;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int row = grid.size(), col = grid[0].size(), t=0, fresh =0;
        queue<pair<int, int>>q;
        for(int i =0; i<row; ++i){
            for(int j =0; j<col; ++j){
                if(grid[i][j]==2) q.push({i,j});
                else if(grid[i][j]==1) fresh++;
            }
        }
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        while(!q.empty()){
            t++;
            int size = q.size();
            for(int i =0; i<size; ++i){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int j =0; j<4; ++j){
                    int xdx = x + dx[j];
                    int ydy = y + dy[j];
                    if(isvalid(xdx, ydy, row, col) && grid[xdx][ydy]==1){
                        grid[xdx][ydy] =2;
                        fresh--;
                        q.push({xdx, ydy});
                    }
                }
            }
            if(fresh==0) return t;
        }
        return -1;
    }



// 994. Rotting Oranges
// Medium

// 8382

// 306

// Add to List

// Share
// You are given an m x n grid where each cell can have one of three values:

// 0 representing an empty cell,
// 1 representing a fresh orange, or
// 2 representing a rotten orange.
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 

// Example 1:


// Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
// Output: 4
// Example 2:

// Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
// Output: -1
// Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
// Example 3:

// Input: grid = [[0,2]]
// Output: 0
// Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 10
// grid[i][j] is 0, 1, or 2.


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> rotten;
        int r = grid.size();
        int c = grid[0].size();
        int fresh = 0;
        int time = 0;
        for(int i= 0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j] == 2) rotten.push({i,j});
                else if(grid[i][j] == 1) fresh++;
            }
        }
        while(!rotten.empty())
        {
            int num = rotten.size();
            for(int i=0;i<num;i++)
            {
                int x = rotten.front().first;
                int y = rotten.front().second;
                rotten.pop();
                if(x > 0 && grid[x-1][y] == 1)
                {
                    grid[x-1][y] = 2;
                    fresh--;
                    rotten.push({x-1, y});
                }
                if(y > 0 && grid[x][y-1] == 1)
                {
                    grid[x][y-1] = 2;
                    fresh--;
                    rotten.push({x, y-1});
                }
                if(x < r-1 && grid[x+1][y] == 1)
                {
                    grid[x+1][y] = 2;
                    fresh--;
                    rotten.push({x+1, y});
                }
                if(y < c-1 && grid[x][y+1] == 1)
                {
                    grid[x][y+1] = 2;
                    fresh--;
                    rotten.push({x, y+1});
                }
            }
            if(!rotten.empty()) time++;
        }
        return (fresh == 0) ? time : -1;
    }
};