class Solution {
public:
    int strStr(string haystack, string needle) 
    {
        // if the size of needle is 0 return 0

        if(needle.size() == 0) return 0;

        // if the first char in haystack matches with first char of needle if it does 
        // we go into second loop and check here if haystack[i+j] is equal to needle[j] then 
        // do additional check that if you are at the end of needle then you have gone through and 
        // found your needle in haystack and you can just return i
        
        for(int i=0;i<haystack.length();i++)
        {
            if(haystack[i] == needle[0])
            {
                for(int j=0;j<needle.length();j++)
                {

                    // this condition is here to adjust the location of i by just iterating through j

                    if(haystack[i+j] == needle[j])
                    {
                        if(j == needle.size()-1)
                        {
                            return i;
                        }
                    }

                    // if the above condition doesn't true if we found char mismatch 
                    // somewhere then we break out of the inner loop and 
                    // go back to the outer for loop to continue

                    else
                    {
                        break;
                    }
                }
            }
        }
        
        // if you have gone through these loop and 
        // never get the opportunity to go into this if statement 
        // here and an index as we have not gone and found we return -1
        
        return -1;
    }
};


https://assets.leetcode.com/users/images/2563a0e2-1729-4dcf-b3cd-c389de35d19e_1630826455.5771935.png

// KMP Algorithm

class Solution {
public:
    int strStr(string haystack, string needle) 
    {
        if(needle.size() == "") return 0;
        int f[needle.length()];
        int i=1;
        int j=0;
        f[0] = 0;
        while(i<needle.length())
        {
            if(needle[j] == needle[i])
            {
                f[i] = j+1;
                i+=1;
                j+=1;
            }
            else if(j>0)
            {
                j = f[j-1];
            }
            else
            {
                f[i] = 0;
                i+=1;
            }
        }
        int m = needle.length(),n = haystack.length();
        i=j=0;
        while(i<n)
        {
            if(needle[j] == haystack[i])
            {
                if(j == m-1)
                {
                    return (i+m+1);
                }
                i+=1;
                j+=1;
            }
            else if(j>0)
            {
                j = f[j-1];
            }
            else
            {
                i+=1;
            }
        }
        return -1;
    }
};