class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        vector<int> answer;
        int top = 0;
        int left = 0;
        int bottom = matrix.size()-1;
        int right = matrix[0].size()-1;

        // top is less than or equal to bottom and left is less than or equal to right

        while(top <= bottom && left <= right)
        {
            
            // traverse from left to right and print the top row element and increment top
            for(int i=left;i<=right;i++)
            answer.push_back(matrix[top][i]); top++;
            // traverse from top to bottom and print tbe 
            for(int i=top;i<=bottom;i++)
            answer.push_back(matrix[i][right]); right--;
            if(top <= bottom)
            {
                for(int i=right;i>=left;i--)
                answer.push_back(matrix[bottom][i]); bottom--;
            }
            if(left <= right)
            {
                for(int i=bottom;i>=top;i--)
                answer.push_back(matrix[i][left]); left++;
            }
        }
        return answer;
    }
};