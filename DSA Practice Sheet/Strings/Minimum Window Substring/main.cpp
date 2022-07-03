class Solution {
public:

    // sliding window technique 
    // storing all characters from string t to an unordered map mp.
    // ans is to store the minimum size of substring start is to store the start index and count is to store the mao size
    // two pointers i and j for iteration j will iterate and will decrement count element in map
    // if value becomes 0 means we got all the elements of that char till so decrement size of count
    // when the count will be 0 if there is a substring with all elements present
    // then incrementing i we check if there is possibility to get smaller substring
    // then store the smaller length to ans & store the ith index in start variable so add the element to our map and increment the count if it is greater than 0
    // if ans length is not equal to int_max return substring from start index to length of ans else return empty string

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


// T.C.:O(m)