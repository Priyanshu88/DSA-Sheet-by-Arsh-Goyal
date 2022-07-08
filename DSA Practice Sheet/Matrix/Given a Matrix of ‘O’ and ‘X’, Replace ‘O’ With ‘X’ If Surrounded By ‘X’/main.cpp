class Solution{
public:

    int row;
    int col;

    // a recursive function to replace previous value 'prevC' at  '(x, y)'
    // and all surrounding values of (x, y) with new value 'newC'


    void floodFill(vector<vector<char>> &screen, int x,int y,char prevC, char newC)
    {

        // base case  If x or y is outside the boundary, then return.

        if(x < 0 || x >= row || y < 0 || y >= col)
        {
            return;
        }

        //  If color of screen[x][y] is not same as prevC, then return

        if(screen[x][y] != prevC)
        {
            return;
        }
        
        // Replace the color at (x, y) 

        screen[x][y] = newC;

        // Recur for possibilities in every directions

        floodFill(screen, x+1, y, prevC, newC);
        floodFill(screen, x-1, y, prevC, newC);
        floodFill(screen, x, y+1, prevC, newC);
        floodFill(screen, x, y-1, prevC, newC);
    }

    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {

        row = n;
        col = m;
        vector<vector<char>> temp = mat;

        // Replace all 'O'  with '-'

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

        // Call floodFill for all '-' lying on edges
        // Left side
        
        for(int i=0;i<n;i++)
        {
            if(temp[i][0] == '-')
            {
                floodFill(temp,i,0,'-','O');
            }
        }

        //  Right side

        for(int i=0;i<n;i++)
        {
            if(temp[i][m-1] == '-')
            {
                floodFill(temp,i,m-1,'-','O');
            }
        }

        // Top side

        for(int i=0;i<m;i++)
        {
            if(temp[0][i] == '-')
            {
                floodFill(temp,0,i,'-','O');
            }
        }

        // Bottom side

        for(int i=0;i<m;i++)
        {
            if(temp[n-1][i] == '-')
            {
                floodFill(temp,n-1,i,'-','O');
            }
        }

        // Replace all '-' with 'X'

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