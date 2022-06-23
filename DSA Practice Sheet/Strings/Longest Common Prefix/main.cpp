class Solution {
public:

    // assuming that first string is the common prefix
    // now iterating through the list of strings and for each 
    // compare how much letter are matching keeps on decreasing the size of prefix
    // as long as we dont't find the prefix

    string longestCommonPrefix(vector<string>& strs) 
    {
        if(strs.size() == 0) return "";
        string Prefix = strs[0];
        for(int i=1;i<strs.size();i++)
        {
            while(strs[i].find(Prefix) != 0)
            {
                Prefix = Prefix.substr(0,Prefix.length()-1);
                if(Prefix.length() == 0) return "";
            }
        }
        return Prefix;
    }
};


// do the sorting first it ensures that the last string must be one of the strings
// having the biggest difference with the first one and we only need to compare the 
// first one and the last one

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        int n = strs.size();
        string ans;
        sort(strs.begin(),strs.end());
        string a = strs[0];
        string b = strs[n-1];
        for(int i=0;i<a.size();i++)
        {
            if(a[i] == b[i])
            {
                ans+=a[i];
            }
            else 
            {
                break;
            }
        }
        return ans;
    }
};