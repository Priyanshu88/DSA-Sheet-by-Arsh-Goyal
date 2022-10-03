// 1209. Remove All Adjacent Duplicates in String II
// Medium

// 4388

// 83

// Add to List

// Share
// You are given a string s and an integer k, a k duplicate removal consists of choosing k adjacent and equal letters from s and removing them, causing the left and the right side of the deleted substring to concatenate together.

// We repeatedly make k duplicate removals on s until we no longer can.

// Return the final string after all such duplicate removals have been made. It is guaranteed that the answer is unique.

 

// Example 1:

// Input: s = "abcd", k = 2
// Output: "abcd"
// Explanation: There's nothing to delete.
// Example 2:

// Input: s = "deeedbbcccbdaa", k = 3
// Output: "aa"
// Explanation: 
// First delete "eee" and "ccc", get "ddbbbdaa"
// Then delete "bbb", get "dddaa"
// Finally delete "ddd", get "aa"
// Example 3:

// Input: s = "pbbcggttciiippooaais", k = 2
// Output: "ps"
 

// Constraints:

// 1 <= s.length <= 105
// 2 <= k <= 104
// s only contains lowercase English letters.

#include<bits/stdc++.h>
using namespace std;


// it looks like we can remove duplicates in any order, so we can greedily search and remove duplicates. The question becomes how efficient your greedy algorithm is.

// Approach 1: Brute-force
// Just keep removing duplicates until there is no more. When we find a duplicate, we call the same function recursively with that duplicate removed.

class Solution {
public:
    string removeDuplicates(string s, int k) 
    {
        for (auto i = 1, cnt = 1; i < s.size(); ++i) 
        {
            if (s[i] != s[i - 1]) cnt = 1;
            else if (++cnt == k)
            return removeDuplicates(s.substr(0, i - k + 1) + s.substr(i + 1), k);
        }
        return s;
    }
};
// Or, we can do the same iteratively. It's a bit harder on eyes but easier on memory :)

class Solution {
    public:

    string removeDuplicates(string s, int k, bool replaced = true) 
    {
        while (replaced) 
        {
            replaced = false;
            for (auto i = 1, cnt = 1; i < s.size() && !replaced; ++i) 
            {
                if (s[i] != s[i - 1]) cnt = 1;
                else if (++cnt == k) 
                {
                    s = s.substr(0, i - k + 1) + s.substr(i + 1);
                    replaced = true;
                }
            }
        }
    }
    return s;
};

class Solution {
public:
    string removeDuplicates(string s, int k) 
    {
        int i = 0, n = s.length();
        vector<int> count(n);
        for (int j = 0; j < n;j++,i++)
        {
            s[i] = s[j];
            count[i] = i > 0 && s[i - 1] == s[j] ? count[i - 1] + 1 : 1;
            if(count[i] == k)
                i -= k;
        }
        return s.substr(0, i);
    }
};


class Solution {
public:
    string removeDuplicates(string s, int k)
    {
        stack<pair<char, int>> st;
        string ans;
        for (int i = s.length() - 1; i >= 0;i--)
        {
            if(st.size() && st.top().first == s[i])
            {
                st.push({s[i], st.top().second + 1});
            }
            else
            {
                st.push({s[i], 1});
            }

            // when the count become equal to k

            if(st.size() && st.top().second==k)
            {
                while(st.top().second != 1)
                {
                    st.pop();
                }
                st.pop();
            }
        }
        while(st.size())
        {
            ans += st.top().first;
            st.pop();
        }
        return ans;
    }

};



class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char,int>> st;
        for(char c : s) {
            if(st.empty() || st.back().first != c) {
                st.push_back({c,1});
            }
            else if(++st.back().second == k ) 
                st.pop_back();
        }
        string result="";
        for(auto t : st) {
            result.append(t.second,t.first);
        }
        return result;
    }
};



class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.size();
        if(n<k)return s;
        stack<pair<char, int>> stack;
        for(int i=0;i<n;i++)
        {
            if(stack.empty() || stack.top().first !=s[i])
            {
                stack.push({s[i],1});
            }
            else
            {
                auto prev = stack.top();
                stack.pop();
                stack.push({s[i], prev.second+1});
                
            }
            
            if(stack.top().second==k)stack.pop();
        }
        string ans = "";
        while(!stack.empty())
        {
            auto curr = stack.top();
            stack.pop();
            while(curr.second--)
            {
                ans.push_back(curr.first);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};