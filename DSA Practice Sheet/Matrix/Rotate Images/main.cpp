


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    /*
    1 2 3
    4 5 6
    7 8 9

    after flipDiagonally :

    9 6 3
    8 5 2
    7 4 1

    after flipHorizontally:

    7 4 1
    8 5 2
    9 6 3
    */

    void rotate(vector<vector<int>>& matrix) 
    {
        flipDiagonally(matrix);
        flipHorizontally(matrix);
    }

    // flipping the matrix diagonally first

    void flipDiagonally(vector<vector<int>> & matrix)
    {
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix.size()-i-1;j++)
            {
                int curr = matrix[i][j];
                matrix[i][j] = matrix[matrix.size()-j-1][matrix.size()-i-1];
                matrix[matrix.size()-j-1][matrix.size()-i-1] = curr;
            }
        }
    }


    // flipping then horizontally with respect to middle row 

    void flipHorizontally(vector<vector<int>> & matrix)
    {
        for(int i=0;i<matrix.size()/2;i++)
        {
            for(int j=0;j<matrix.size();j++)
            {
                int curr = matrix[i][j];
                matrix[i][j] = matrix[matrix.size()-i-1][j];
                matrix[matrix.size()-i-1][j] = curr;
            }
        }
    }
};



// T.C. :O(n^2)
// S.C. :O(n)