class Solution {
public:
    
    // two pointers approach
    // i from 0 and j from last index, check for i and j if they are
    // equal then just move the pointers. if they are not i.e.(i!=j) then delete ith char and check from
    // i+1 to j for a palindrome, if palindrome return true or then delete jth index char and check from i to j-1
    // for palindrome if yes return true
    
    bool isPalindrome(string s,int i,int j)
    {
        while(i<j)
        {
            if(s[i] == s[j])
            {
                i++;
                j--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
    bool validPalindrome(string s) 
    {
        int i=0;
        int j=s.size()-1;
        while(i<j)
        {
            if(s[i] == s[j])
            {
                i++;
                j--;
            }
            else
            {
                return isPalindrome(s,i+1,j) || isPalindrome(s,i,j-1);
            }
        }
        return true;
    }
};