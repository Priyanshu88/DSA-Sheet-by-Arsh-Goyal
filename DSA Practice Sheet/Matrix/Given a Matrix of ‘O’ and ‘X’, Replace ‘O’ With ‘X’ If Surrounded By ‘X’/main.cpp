class Solution{
public:

    int row;
    int col;

    void floodFill(vector<vector<char>> &screen, int x,int y,char prevC, char newC)
    {
        if(x < 0 || x >= row || y < 0 || y >= col)
        {
            return;
        }
        if(screen[x][y] != prevC)
        {
            return;
        }

        screen[x][y] = newC;
        floodFill(screen, x+1, y, prevC, newC);
        floodFill(screen, x-1, y, prevC, newC);
        floodFill(screen, x, y+1, prevC, newC);
        floodFill(screen, x, y-1, prevC, newC);
    }

    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        N = n;
        M = m;
        vector<vector<char>> temp = mat;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(temp[i][j] == 'O')
                {
                    temp[i][j] = '-';
                }
            }
        }

        for(int i=0;i<n;i++)
        {
            if(temp[i][0] == '-')
            {
                floodFill(temp,i,0,'-','O');
            }
        }

        for(int i=0;i<n;i++)
        {
            if(temp[i][m-1] == '-')
            {
                floodFill(temp,i,m-1,'-','O');
            }
        }

        for(int i=0;i<m;i++)
        {
            if(temp[0][i] == '-')
            {
                floodFill(temp,0,i,'-','O');
            }
        }

        for(int i=0;i<m;i++)
        {
            if(temp[n-1][i] == '-')
            {
                floodFill(temp,n-1,i,'-','O');
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(temp[i][j] == '-')
                {
                    temp[i][j] = 'X';
                }
            }
        }
        return temp;
    }
};