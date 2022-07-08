class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        vector<int> answer;
        
        // starting row index
        
        int top = 0;

        // starting column index

        int left = 0;

        // ending row index

        int bottom  = matrix.size()-1;

        // ending column index

        int right = matrix[0].size()-1;

        // running a loop until all the squares of loops are printed
        // in each outer loop traversal print the elements of a square in a clockwise manner

        while(top <= bottom && left <= right)
        {

            // Print the top row, i.e. Print the elements of the top row from column index left to right, and increase the count of top

            for(int i=left;i<=right;i++)
            answer.push_back(matrix[top][i]); top++;

            // Print the right column, i.e. Print the last column or right column from row index top to bottom and decrease the count of right

            for(int i=top;i<=bottom;i++)
            answer.push_back(matrix[i][right]); right--;

            // Print the bottom row, i.e. if top < bottom, then print the elements of bottom row from column right to left and decrease the count of bottom
            
            if(top <= bottom)
            {
                for(int i=right;i>=left;i--)
                {
                    answer.push_back(matrix[bottom][i]); bottom--;
                }
            }

            // Print the left column, i.e. if left < right, then print the elements of left column from bottom row to top and increase the count of left

            if(left <= right)
            {
                for(int i=bottom;i>=top;i--)
                {
                    answer.push_back(matrix[i][left]); left++;
                }
            }
        }

        // return the matrix

        return answer;
    }
};