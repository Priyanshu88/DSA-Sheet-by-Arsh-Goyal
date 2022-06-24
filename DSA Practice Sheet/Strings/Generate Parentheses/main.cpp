class Solution {
public:
    
    // Instead of trying out both the brackets at each index of the
    // string, we only try them at places which won't outright invalidate the string.
    // The 2 cases:
    // ( can be inserted anywhere till its count is less than n
    // ) can be inserted whenever its count is less than number of opening parentheses
    // and insert the string when its length reaches 2*n.
    
    vector<string>res;
    vector<string> generateParenthesis(int n) 
    {
        permute(0,0,n,"");
        return res;
    }

    void permute(int open,int close,int n,string p)
    {
        if(p.length() == 2*n)
        {
            res.push_back(p);
        }
        if(open < n) permute(open+1,close,n,p+"(");
        if(close < open) permute(open,close+1,n,p+")");
    }
};