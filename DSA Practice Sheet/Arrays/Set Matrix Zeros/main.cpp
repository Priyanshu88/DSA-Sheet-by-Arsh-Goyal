class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
    int r = matrix.size();
    int c = matrix[0].size();
    bool rowZero = false;
    bool colZero = false;

    // if 0 is present in first column

    for(int i=0;i<r;i++)
    {
        if(matrix[i][0] == 0)
        {
            colZero = true;
            break;
        }
    }

    // if 0 is present is first row

    for (int i=0;i<c;i++)
    {
        if(matrix[0][i] == 0)
        {
            rowZero = true;
            break;
        }
    }

    // check elements except first row & column

    for (int i=1;i<r;i++)
    {
        for(int j=1;j<c;j++)
        {
            if(matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // process all except first row & column

    for (int i=1;i<r;i++)
    {
        for(int j=1;j<c;j++)
        {
            if(matrix[i][0] == 0 || matrix[0][j] == 0)
            {
                matrix[i][j] = 0;
            }
        }
    }

    // process first column

    if(colZero == true)
    {
        for(int i = 0;i<r;i++)
        {
            matrix[i][0] = 0;
        }
    }


    // processing first column

    if(rowZero == true)
    {
        for (int i=0;i<c;i++)
        {
            matrix[0][i] = 0;
        }
    }
    }
};