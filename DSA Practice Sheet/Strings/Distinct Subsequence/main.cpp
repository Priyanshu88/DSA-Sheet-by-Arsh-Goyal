class Solution {
    private:
    int func(int i,int j,string s,string t, vector<vector<int>>& dp)
    {
        if(j < 0) return 1;
        if (i < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if (s[i] == t[j]) 
        {
            return dp[i][j] = func(i-1,j-1,s,t,dp) + func(i-1,j,s,t,dp);
        }
        else
            return dp[i][j] = func(i-1,j,s,t,dp);
    }
public:
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        return func(n-1,m-1,s,t,dp);
    }
};




class Solution {
    private:
    int func(int i,int j,string s,string t, vector<vector<int>>& dp)
    {
        if(j == 0) return 1;
        if (i == 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if (s[i-1] == t[j-1]) 
        {
            return dp[i][j] = func(i-1,j-1,s,t,dp) + func(i-1,j,s,t,dp);
        }
        else
            return dp[i][j] = func(i-1,j,s,t,dp);
    }
public:
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        
        
        vector<vector<double>> dp(n+1, vector<double>(m+1,0));
        
        
        for(int i=0;i<=n;i++) dp[i][0] = 1;
        // for(int j=0;j<=m;j++) dp[0][j] = 0;
        
        
        for(int i=1;i<=n;i++)
        {
            for(int j = 1;j<=m;j++)
            {
                if(s[i-1] == t[j-1])
                {
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                    
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
                
            }
        }
        return (int)dp[n][m];
    }
};




class Solution {
    private:
    int func(int i,int j,string s,string t, vector<vector<int>>& dp)
    {
        if(j == 0) return 1;
        if (i == 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if (s[i-1] == t[j-1]) 
        {
            return dp[i][j] = func(i-1,j-1,s,t,dp) + func(i-1,j,s,t,dp);
        }
        else
            return dp[i][j] = func(i-1,j,s,t,dp);
    }
public:
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        
        
        vector<double> dp(m+1,0);
        
        dp[0]= 1;
        
        
        
        for(int i=1;i<=n;i++)
        {
            for(int j = m;j>=1;j--)
            {
                if(s[i-1] == t[j-1])
                {
                    dp[j] = dp[j-1] + dp[j];
                    
                }
                
            }
        }
        return (int)dp[m];
    }
};