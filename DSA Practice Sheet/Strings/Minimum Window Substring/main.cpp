class Solution {
public:
    string minWindow(string s, string t) 
    {
        int m = s.length();
        int n = t.length();
        unordered_map<char,int> mp;
        int ans = INT_MAX;
        int start = 0;
        int i = 0;
        int j = 0;
        for(auto a:t)
        {
            mp[a]++;
        }

        int count = mp.size();


        while(j < s.length())
        {
            mp[s[j]]--;
            if(mp[s[j]] == 0)
            {
                count--;
            }

            if(count == 0)
            {
                while(count == 0)
                {
                    if(ans > j-i+1)
                    {
                        ans = j-i+1;
                        start = i;
                    }
                    mp[s[i]]++;
                    if(mp[s[i]] > 0)
                    {
                        count++;
                    }
                    i++;
                }
            }
            j++;
        }
        if(ans != INT_MAX)
        {
            return s.substr(start,ans);
        }
        else return "";
    }
};