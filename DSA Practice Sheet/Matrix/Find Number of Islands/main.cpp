// #include <bits/stdc++.h>
// using namespace std;

// #define ROW 5
// #define COL 5


// // a function to check if a given cell (row, col) can be included in DFS


// int isSafe(int M[][COL],int row, int col,bool visited[][COL])
// {

//     // row number is in range, column
//     // number is in range and value is 1
//     // and not yet visited

//     return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL) && (M[row][COL] && !visited[row][col]);

// }


// // A function to do DFS for a 2D matrix. It only considers the 8 neighbors as adjacent vertices

// void DFS(int M[][COL], int row, int col, bool visited[][COL])
// {

//     // these arrays are used to get row and column numbers of 8
//     // neighbors of a given cell

//     static int rowNum[] = {-1,-1,-1,0,0,1,1,1};
//     static int colNum[] = {-1,0,1,-1,1,-1,0,1};

//     visited[row][col] = true;

//     for(int k=0;k<8;k++)
//     {
//         if(isSafe(M, row + rowNum[k], col + colNum[k], visited));
//         DFS(M, row + rowNum[k], col + colNum[k], visited);
//     }
// }



// // The main function that returns
// // count of islands in a given boolean
// // 2D matrix



// int countIslands(int M[][COL])
// {

//     // make a bool array to mark visited cells
//     // initially all cells are unvisited

//     bool visited[ROW][COL];
//     memset(visited,0,sizeof(visited));

//     // initialize count as 0 and traverse
//     // through the all cells of given matrix

//     int count = 0;
//     for(int i=0;i<ROW;i++)
//     {
//         for(int j=0;j<COL;j++)
//         {

//             // if a cell with value 1 is not

//             if(M[i][j] && !visited[i][j])
//             {

//                 // visited yet, then new island found
//                 // visit all cells in this island

//                 DFS(M,i,j,visited);
                
//                 // and increment island count

//                 count++;
//             }

//         }
//     }
//     return count;

// }


// int main()
// {

//     int M[][COL] =  {
//                     {1,1,0,0,0},
//                     {0,1,0,0,1},
//                     {1,0,0,1,1},
//                     {0,0,0,0,0},
//                     {1,0,1,0,1},
//                     };

//     cout << "Number of islands is: " << countIslands(M);
    
//     return 0;

// }

// T.C. : O(R*C)
// S.C. : O(R*C)



    #include <bits/stdc++.h>
    using namespace std;

    // A function to do DFS for a 2D
    // boolean matrix. It only considers
    // the 8 neighbors as adjacent vertices


    void DFS(vector<vector<int>> &M, int i,int j,int ROW,int COL)
    {

        // Base condition
        // if i is less than 0 or j is less than 0 or i is greater than ROW-1 or greater than COL-1 or if M[i][j]

        if(i < 0 || j < 0 || i > (ROW-1) || j > (COL-1) || M[i][j] != 1)
        {
            return;
        }

        if(M[i][j] == 1)
        {
            M[i][j] = 0;
            DFS(M,i+1,j,ROW,COL);
            DFS(M,i-1,j,ROW,COL);
            DFS(M,i,j+1,ROW,COL);
            DFS(M,i,j-1,ROW,COL);
            DFS(M,i+1,j+1,ROW,COL);
            DFS(M,i-1,j-1,ROW,COL);
            DFS(M,i+1,j-1,ROW,COL);
            DFS(M,i-1,j+1,ROW,COL);

        }


    }



    // Function to find the number of islands.

    int numIslands(vector<vector<int>>& M) 
    {

        int ROW = M.size();
        int COL = M[0].size();
        int count = 0;
        for(int i=0;i<ROW;i++)
        {
            for(int j=0;j<COL;j++)
            {
                if(M[i][j] == 1)
                {
                    M[i][j] = 0;
                    count++;
                    DFS(M,i+1,j,ROW,COL);   // right side traversal
                    DFS(M,i-1,j,ROW,COL);   // left side traversal
                    DFS(M,i,j+1,ROW,COL);   // upward side traversal
                    DFS(M,i,j-1,ROW,COL);   // downward side traversal
                    DFS(M,i+1,j+1,ROW,COL); // upward-right side traversal
                    DFS(M,i-1,j-1,ROW,COL); // downward-left side traversal
                    DFS(M,i+1,j-1,ROW,COL); // downward-right side traversal
                    DFS(M,i-1,j+1,ROW,COL); // upward-left side traversal
                }
            }
        }
        return count;
    }


    int main()
    {
        vector<vector<int>> M = {
                                {1,1,0,0,0},
                                {0,1,0,0,1},
                                {1,0,0,1,1},
                                {0,0,0,0,0},
                                {1,0,1,0,1},
                                };

        cout << "Number of islands: " << numIslands(M);
        return 0;
    }


// T.C.:O(R*C)
// S.C.:O(1)


// take a queue and a 2d array named status
// traverse the given matrix
// if current element is 1 and not visited
// mark it visited and push it into queue
// increase the count of number of islands

// while queue is not empty
// take front element
// put all the adjacent into queue and mark them visited




class Solution
{
    public:

    // these lists are used to get row and column numbers of 8
    // neighbors of a given cell

    vector<int> dx = {-1,0,1,0,1,-1,-1,1};
    vector<int> dy = {0,-1,0,1,1,1,-1,-1};


    bool isValid(int x,int y,int n,int m)
    {
        return (x>=0 and x<n and y>=0 and y < m);
    }

    // function to find the number of islands

    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        // boolean array to mark visited cells 
        // initially all cells are unvisited

        vector<vector<bool>> vis(n,vector<bool>(m,false));

        // using queue for BFS
        queue<pair<int,int>> q;
        int ans = 0;

        // if current element is 1 and not visited
        // mark it as visited and push it into queue
        // and increase the count of number of islands

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] and grid[i][j] == '1')
                {
                    ans++;
                    vis[i][j] = true;

                    q.push({i,j});

                    // while queue is not empty
                    // take front element
                    // and put all the adjacent into queue and mark them visited

                    while (!q.empty())
                    {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();

                        for(int k=0;k<8;k++)
                        {

                            // if current index is valid and not visites and value at that index is 1
                            // then push it into queue and mark as visited

                            if (isValid(x + dx[k], y + dy[k], n, m) and !vis[x + dx[k]][y + dy[k]] and grid[x + dx[k]][y + dy[k]] == '1')
                            {
                                q.push({x+dx[k],y+dy[k]});
                                vis[x+dx[k]][y+dy[k]] = true;
                            }
                        }
                    }
                    
                }
            }
        }
        return ans;
    }
};
