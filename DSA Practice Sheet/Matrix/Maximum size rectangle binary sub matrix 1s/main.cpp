#include<bits/stdc++.h>
using namespace std;

// taking rows and column as input for the matrix

#define n 4
#define m 4

// finding maximum area under the histogram represented by histogram

int maxHist(int row[])
{

    // creating an empty stack stack holds the indexes of hist[]
    // bars stores in stack are always in increasing order of their heights

    stack<int> answer;

    // top of the stack

    int top_val;

    // initializing max area in current row


    int max_area = 0;    

    // initialize area with current top

    int area = 0;

    // run through all bars of given histogram (or row)

    int i =0;
    while(i < m)
    {

        // if this bar is higher than the bar on top  of stack then push it to stack

        if(answer.empty() || row[answer.top()] <= row[i])
        answer.push(i++);
        else
        {

            // if this bar is lower than top of the stack then calculate area of rectangle with stack top as the smallest 
            // (or minimum height) bar. 'i' is the 'right index' for the top and element before top in stack is 'left index'

            top_val = row[answer.top()];
            answer.pop();
            area = top_val*i;
            if(!answer.empty())
            {
                area = top_val * (i-answer.top()-1);
            }
            max_area = max(area,max_area);
        }
    }

    // now pop the remaining bars from stack and calculate area with every popped bars as the smallest bar

    while(!answer.empty())
    {
        top_val = row[answer.top()];
        answer.pop();
        area = top_val*i;
        if(!answer.empty())
        {
            area = top_val*(i-answer.top()-1);
        }
        max_area = max(area,max_area);
    }
    return max_area;
}


// returns area of the largest rectangle with all 1s in A[][]



int maxRectangle(int M[][m])
{

    // calculate area for the first row and initialize it as answer

    int answer = maxHist(M[0]);

    // iterate over row to find maximum rectangular area considering each row as histogram

    for(int i=1;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {

            // if M[i][j] is true/1 then add M[i-1][j] into it

            if(M[i][j])
            {

                M[i][j] += M[i-1][j];
            }

            // update answer if area with current row (as last row of rectangle is more)

            answer = max(answer,maxHist(M[i]));
        }
        return answer;
    }
}





// We get the largest rectangle full of 1's, update the next row with the previous row
// and find the largest area under the histogram, i.e. consider each 1's as filled squares and 0's 
// with an empty square and consider each row as the base.




class Solution
{
    public:

    int maxHist(int A[],int m)
    {
        stack<int> answer;
        int top_val;
        int max_area;
        int area = 0;
        int i=0;
        while(i < m)
        {
            if(answer.empty() || A[answer.top() <= A[i]])
            answer.push(i++);
            else
            {
                top_val = A[answer.top()];
                answer.pop();
                area = top_val*i;
                if(!answer.empty())
                {
                    area = top_val * (i-answer.top()-1);
                }
                max_area = max(area,max_area);
            }
        }


        while(!answer.empty())
        {
            top_val = A[answer.top()];
            answer.pop();
            area = top_val*i;
            if(!answer.empty())  area = top_val * (i-answer.top() - 1);
            max_area = max(area, max_area);
        }
        return max_area;

    }


    int maxRect(int M[MAX][MAX],int n,int m)
    {
        int ans = maxHist(M[0],m);
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(M[i][j])  M[i][j] += M[i-1][j];
            }
            ans = max(ans,maxHist(M[i],m))
        }
        return ans;
    }




    int maxArea(int M[MAX][MAX], int n, int m) 
    {

        return maxRect(M,n,m);
    }



};
