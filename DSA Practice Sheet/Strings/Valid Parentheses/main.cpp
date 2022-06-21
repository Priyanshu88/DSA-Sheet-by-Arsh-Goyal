class Solution {
public:
    bool isValid(string s) 
    { 

        // taking stack for maintaining order
        // if current element of the string is opening bracket then we will just simply push it into the stack
        // if it is closing bracket then check current element matches with top of the stack and the stack must not be empty then return false
        
        stack<char> st; 
        for(auto i:s)
        {
            if(i == '(' || i == '{' || i == '[')
            st.push(i);
            else
            {
                if(st.empty() || (st.top() == '(' && i != ')') || (st.top() == '{' && i != '}') || (st.top() == '[' && i != ']'))
                return false;
                
                // we have got the right pair of brackets, so just pop it.
                
                st.pop();
            }
        }

        // lastly check if the stack is empty or not

        return st.empty();
    }
};