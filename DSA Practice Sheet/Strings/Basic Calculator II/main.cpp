class Solution {
public:

    // Scan the input string s from left to right and evaluate the expressions based on following rules:
    //  if we encounter a digit/num (The string might also contain more than 1 digit numbers, so until we find any operator,
    //  we'll keep on forming the multi digit number (num = num*10 + s[i] ) 
    // When we encounter a operator, we stop & check the previous operator :
    //  ** If operator = '+' (i.e; the previous operator was +), we just push currentNum into the stack ('Cause this value needs to be added to ans).
    //  ** If operator = '-', (i.e; the previous operator was -), we toggle curr's operator and push it into the stack ('Cause this value needs to be subtracted from ans).
    //  ** If operator = '*', (i.e; we encountered a x sign previously), then the  value should be multiplied with it and then added to ans, so we pop the top of the stack, multiply it with the current value and push the result into the stack.
    //  ** If operator = '/', i.e; we encountered a / previously, then the curr value should divide the previous value ans, so we pop the top of the stack, divide it with curr and push the result into the stack.
    //  At the end, we encounter another '+' sign, this is to push the last curr value into the stack.
    //  Finally we have obtained a stack of values all of which only need to be added to obtain the ans.
    //  So pop the values from stack one by one, add them to ans, and return the ans
    
    int calculate(string s) 
    {
        int n = s.length();
        if(n == 0) return 0;
        stack<int> stk;
        int currentNum = 0;

        // for storing the previous sign

        char operation = '+';
        for(int i=0;i<n;i++)
        {
            char currCh = s[i];

            // keep forming the number, until an operator is being found  

            if(isdigit(currCh)) currentNum = (currentNum * 10) + (currCh - '0');
            if(i == s.length()-1 || currCh == '+' || currCh == '-' || currCh == '*' || currCh == '/')
            {
                
                // add it to stk

                if(operation == '+') stk.push(currentNum);

                // add it to stk after multiplying with -1
                
                else if(operation == '-') stk.push(currentNum*(-1));
                
                // store top element then pop the top and push multiplication of curentNum and top 

                else if(operation == '*')
                {
                    int top = stk.top();
                    stk.pop();
                    stk.push(currentNum*top);
                }

                // store top element then pop the top and push dividation of curentNum and top 


                else if(operation == '/')
                {
                    int top = stk.top();
                    stk.pop();
                    stk.push(top/currentNum);
                }
                currentNum = 0;
                operation = currCh;
            }

        }
        int ans = 0;
        while(stk.size())
        {
            ans += stk.top();
            stk.pop();
        }
        return ans;
    }
};




// add the values to the result beforehand and keep track of the last calculated number, thus eliminating the need for the stack. 
// use a variable lastNum to track the value of the last evaluated expression. If the operation is Addition (+) or Subtraction (-), add the lastNum to the ans. The currentNum would be updated to lastNum for the next iteration.
// If the operation is Multiplication (*) or Division (/), evaluate the expression lastNum * currentNum and update the lastNum with the ans of the expression. This would be added to the ans after the entire string is scanned.

class Solution {
public:
    int calculate(string s) 
    {
        int n = s.length();
        if(n == 0) return 0;
        int currentNum = 0, lastNum = 0,answer = 0;
        char operation = '+';
        for(int i=0;i<n;i++)
        {
            char currCh = s[i];
            if(isdigit(currCh)) currentNum = (currentNum*10) + (currCh - '0');
            if(i == n-1 || currCh == '+' || currCh == '-' || currCh == '*' || currCh == '/')
            {
                if(operation == '+') 
                {
                    answer += lastNum;
                    lastNum = currentNum;
                }
                else if(operation == '-')
                {
                    answer += lastNum;
                    lastNum = -currentNum;
                }
                else if(operation == '*')
                {
                    lastNum = lastNum*currentNum;
                }
                else if(operation == '/')
                {
                    lastNum = lastNum*currentNum;
                }
                currentNum = 0;
                operation = currCh;
            }
        }
        answer += lastNum;
        return answer;
    }
};