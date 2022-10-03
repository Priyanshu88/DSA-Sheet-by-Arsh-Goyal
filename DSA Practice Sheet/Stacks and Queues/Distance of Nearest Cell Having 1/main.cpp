// Given a binary matrix of N x M, containing at least a value 1. The task is to find the distance of nearest 1 in the matrix for each cell. The distance is calculated as |i1 - i2| + |j1 - j2|, where i1, j1 are the row number and column number of the current cell and i2, j2 are the row number and column number of the nearest cell having value 1.

// Examples: 

// Input : N = 3, M = 4
//         mat[][] = { 0, 0, 0, 1,
//                     0, 0, 1, 1,
//                     0, 1, 1, 0 }
// Output : 3 2 1 0
//          2 1 0 0
//          1 0 0 1
// Explanation:
// For cell at (0, 0), nearest 1 is at (0, 3),
// so distance = (0 - 0) + (3 - 0) = 3.
// Similarly, all the distance can be calculated.

// Input : N = 3, M = 3
//         mat[][] = { 1, 0, 0, 
//             0, 0, 1, 
//             0, 1, 1 }
// Output :
//        0 1 1 
//        1 1 0 
//        1 0 0 
// Explanation:
// For cell at (0, 1), nearest 1 is at (0, 0), so distance
// is 1. Similarly, all the distance can be calculated.

// Method 1: This method uses a simple brute force approach to arrive at the solution.

// Approach: The idea is to traverse the matrix for each cell and find the minimum distance, To find the minimum distance traverse the matrix and find the cell which contains 1 and calculates the distance between two cells and store the minimum distance.
// Algorithm : 
// Traverse the matrix from start to end (using two nested loops)
// For every element find the closest element which contains 1. To find the closest element traverse the matrix and find the minimum distance.
// Fill the minimum distance in the matrix.


#include<bits/stdc++.h>
#define N 3
#define M 4
using namespace std;

// Print the distance of nearest cell
// having 1 for each cell.

void printDistance(int mat[N][M])
{
    int ans[N][M];

    // Initialize the answer matrix with INT_MAX.

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            ans[i][j] = INT_MAX;

    // For each cell

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {

            // Traversing the whole matrix
            // to find the minimum distance.

            for (int k = 0; k < N; k++)
                for (int l = 0; l < M; l++)
                {
                
                    // If cell contain 1, check
                    // for minimum distance.
                
                    if (mat[k][l] == 1)
                        ans[i][j] = min(ans[i][j],
                            abs(i-k) + abs(j-l));
                }
        }

    // Printing the answer.

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            cout << ans[i][j] << " ";

        cout << endl;
    }
}

// Driven Program

int main()
{
    int mat[N][M] =
    {
        0, 0, 0, 1,
        0, 0, 1, 1,
        0, 1, 1, 0
    };

    printDistance(mat);

    return 0;
}


// Distance of nearest cell having 1
// MediumAccuracy: 51.53%Submissions: 21396Points: 4
// Given a binary grid of n*m. Find the distance of the nearest 1 in the grid for each cell.
// The distance is calculated as |i1  - i2| + |j1 - j2|, where i1, j1 are the row number and column number of the current cell, and i2, j2 are the row number and column number of the nearest cell having value 1.


// Example 1:

// Input: grid = {{0,1,1,0},{1,1,0,0},{0,0,1,1}}
// Output: {{1,0,0,1},{0,0,1,1},{1,1,0,0}}
// Explanation: The grid is-
// 0 1 1 0 
// 1 1 0 0 
// 0 0 1 1 
// 0's at (0,0), (0,3), (1,2), (1,3), (2,0) and
// (2,1) are at a distance of 1 from 1's at (0,1),
// (0,2), (0,2), (2,3), (1,0) and (1,1)
// respectively.
// Example 2:

// Input: grid = {{1,0,1},{1,1,0},{1,0,0}}
// Output: {{0,1,0},{0,0,1},{0,1,2}}
// Explanation: The grid is-
// 1 0 1
// 1 1 0
// 1 0 0
// 0's at (0,1), (1,2), (2,1) and (2,2) are at a 
// distance of 1, 1, 1 and 2 from 1's at (0,0),
// (0,2), (2,0) and (1,1) respectively.


// Yout Task:
// You don't need to read or print anything, Your task is to complete the function nearest() which takes the grid as an input parameter and returns a matrix of the same dimensions where the value at index (i, j) in the resultant matrix signifies the minimum distance of 1 in the matrix from grid[i][j].


// Expected Time Complexity: O(n*m)
// Expected Auxiliary Space: O(n*m)

// Constraints:
// 1 ≤ n, m ≤ 500

#include<bits/stdc++.h>
using namespace std;


class Solution
{
    public:

    //Function to find distance of nearest 1 in the grid for each cell.
	

    bool check(int i,int j,int n,int m)
    {
        if(i<0 || j<0 || i>=n || j>=m)
            return false;
        return true;
    }

    
    vector<vector<int>>nearest(vector<vector<int>>grid)
	{
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> ans(n, vector<int>(m, -1));

        for (int i = 0; i < n;i++)
        {
            for (int j = 0; j < m;j++)
            {
                if(grid[i][j] == 1)
                {
                    q.push({i, j});
                    ans[i][j] = 0;
                }
            }
        }

        while(!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            if(check(i-1,j,n,m)&&ans[i-1][j] == -1)
            {
                ans[i - 1][j] = ans[i][j] + 1;
                q.push({i - 1, j});
            }
            if(check(i,j-1,n,m)&&ans[i][j-1] == -1)
            {
                ans[i][j - 1] = ans[i][j] + 1;
                q.push({i, j - 1});
            }
            if(check(i,j+1,n,m)&&ans[i][j+1] == -1)
            {
                ans[i][j + 1] = ans[i][j] + 1;
                q.push({i, j + 1});
            }
            if(check(i+1,j,n,m)&&ans[i+1][j] == -1)
            {
                ans[i + 1][j] = ans[i][j] + 1;
                q.push({i + 1, j});
            }
        }
        return ans;
    }
};




vector<vector<int>>nearest(vector<vector<int>>grid)
{
	int n = grid.size(), m = grid[0].size();
	vector<vector<int>> ans(n, vector<int>(m, 0));
	queue<pair<int,pair<int,int>>> q;
	for(int i=0; i<n; i++) 
    {
        for(int j=0; j<m; j++) 
        {
            if(grid[i][j]==0)
                ans[i][j] = INT_MAX;
            else
            q.push({0, {i,j}});
        }
	}
	int dx[] = {-1, 0, +1, 0};
	int dy[] = {0, +1, 0, -1};
	while(!q.empty()) 
    {
        int x = q.front().second.first;
        int y = q.front().second.second;
        int dis = q.front().first;
        q.pop();
        for(int i=0; i<4; i++) 
        {
            int newX = x+dx[i];
            int newY = y+dy[i];
            if(newX>=0 && newX<n && newY>=0 && newY<m && 1+dis<ans[newX][newY]) 
            {
                ans[newX][newY] = 1 + dis;
                q.push({1+dis, {newX, newY}});
                }
        }
	}
	return ans;
}


class Solution 
{
    public:
    vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> res(n, vector<int>(m, INT_MAX));
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                q.push({i, j});
                res[i][j] = 0;
            }
        }
    }

    vector<pair<int, int>> move = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    while (!q.empty())
    {

        int currX = q.front().first;
        int currY = q.front().second;
        q.pop();

        for (auto moves : move)
        {
            int x = currX + moves.first;
            int y = currY + moves.second;

            if (x < 0 || y < 0 || x >= n || y >= m)
                continue;
            else
            {
                if (res[x][y] > res[currX][currY] + 1)
                {
                    res[x][y] = res[currX][currY] + 1;
                    q.push({x, y});
                }
            }
        }
    }
    return res;
	}
};



// https://www.youtube.com/watch?v=wtRT9G42g4g


class Solution 
{
    public:

    //Function to find distance of nearest 1 in the grid for each cell.
	
    vector<vector<int>>nearest(vector<vector<int>>grid)
	{
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> ans(n,vector<int>(m,INT_MAX));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 1)
                {
                    ans[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            if((i-1)>=0 && ans[i][j]+1 < ans[i-1][j])
            {
                ans[i-1][j] = ans[i][j]+1;
                q.push({i-1,j});
            }
            if((j-1)>=0 && ans[i][j]+1 < ans[i][j-1])
            {
                ans[i][j-1] = ans[i][j]+1;
                q.push({i,j-1});
            }
            if((i+1)<n && ans[i][j]+1 < ans[i+1][j])
            {
                ans[i+1][j] = ans[i][j]+1;
                q.push({i+1,j});
            }
            if((j+1)<m && ans[i][j]+1 < ans[i][j+1])
            {
                ans[i][j+1] = ans[i][j] +1;
                q.push({i,j+1});
            }
            q.pop();
        }
        return ans;
	}
};

// 1 0 1
// 1 1 0
// 1 0 0
// (0,0) (0,2) (1,0) (1,1) (2,0) (0,1) (1,2) (2,1) (2,2)

// 0 1 0
// 0 0 1
// 0 1 2

// M M M 0
// 0 1 2 1
// M M M 2


// 0 0 0 1
// 1 0 0 0
// 0 0 0 0