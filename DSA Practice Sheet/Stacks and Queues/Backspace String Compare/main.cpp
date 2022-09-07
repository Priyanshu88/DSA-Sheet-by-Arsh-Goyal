// 844. Backspace String Compare

// Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.

// Note that after backspacing an empty text, the text will continue empty.

 

// Example 1:

// Input: s = "ab#c", t = "ad#c"
// Output: true
// Explanation: Both s and t become "ac".
// Example 2:

// Input: s = "ab##", t = "c#d#"
// Output: true
// Explanation: Both s and t become "".
// Example 3:

// Input: s = "a#c", t = "b"
// Output: false
// Explanation: s becomes "c" while t becomes "b".
 

// Constraints:

// 1 <= s.length, t.length <= 200
// s and t only contain lowercase letters and '#' characters.

// Follow up: Can you solve it in O(n) time and O(1) space?

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) 
    {
        return helper(s) == helper(t);
    }
    string helper(string s)
    {
        stack<char> stk;
        for(auto it: s)
        {

            // if it does not equal to # push element into the queue

            if(it!='#')
            {
                stk.push(it);

            }

            // if stk is not empty
            // pop from the stack

            else if(!stk.empty())
            {
                stk.pop();
            }
        }

        // ans string

        string ans = "";
        
        // if stk is not empty

        while(!stk.empty())
        {

            // push top of the stack into ans 

            ans.push_back(stk.top());

            // pop the stack element

            stk.pop();

        }

        // return the ans

        return ans;
    }
};

// T.C.O(M+N)
// S.C.O(M+N)


class Solution {
public:
    bool backspaceCompare(string s, string t) 
    {
        int i = s.length() - 1, j = t.length() - 1;
        int skipS = 0, skipT = 0;
        while(i>=0||j>=0)
        {

            // While there may be chars in build(S) or build (T)

            while(i>0)
            {
                
                // Find position of next possible char in build(S)

                if(s[i] == '#')
                {
                    skipS++;
                    i--;
                }
                else if(skipS>0)
                {
                    skipS--;
                    i--;
                }
                else
                    break;
            }
            while(j > 0)
            {

                // Find position of next possible char in build(T)

                if(t[j] == '#')
                {
                    skipT++;
                    j--;
                }
                else if(skipT > 0)
                {
                    skipT--;
                    j--;
                }
                else
                    break;
            }

            // If two actual characters are different

            if(i>=0&&j>=0&&s[i]!=t[j])
                return false;
            
            // If expecting to compare char vs nothing

            if((i>=0) != (j>=0))
                return false;
            i--;
            j--;
        }
        return true;
    }
};

// Time Complexity: O(M + N), where M,N are the lengths of S and T respectively.

// Space Complexity: O(1).