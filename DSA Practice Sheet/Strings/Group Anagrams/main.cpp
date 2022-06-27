class Solution
{
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) 
        {

            // sort the strings and compare if it matches with others if yes then let the sorted string be
            // the key of hash map and the value as the string from which it is sorted 
            // after creating hashmap with all elements iterate over the map and print the vector of vectors of strings

            if(strs.size() == 0)
            return {{strs[0]}};
            vector<vector<string>> ans;
            unordered_map<string,vector<string>> my_map;
            for(int i=0;i<strs.size();i++)
            {
                string c = strs[i];

                // // Sorting the string
                
                sort(strs[i].begin(),strs[i].end());

                // // Sorted string is the key and the value is the initial string

                my_map[strs[i]].push_back(c);
            }
            for(auto i = my_map.begin(); i != my_map.end();i++)
            
            // // Traversing the map and adding the vectors of string to ans

            ans.push_back(i->second);
            return ans;
        }
};





    // maintaining a map, iterate over the list of words 
    // prepare a array of A of value of characters
    // for every character in word A[c-'a']++
    // insert the value if they are anagram

class Solution {
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        unordered_map<string,vector<string>> mp;
        vector<vector<string>> res;
        for(string s:strs)
        {
            vector<int> A(26,0);
            for(char c:s)
            A[c-'a']++;
            string r = "";
            for(int i=0;i<26;i++)
            r += A[i];
            mp[r].push_back(s);
        }

        for(auto it:m)
        res.push_back(it.second);
        return res;
    }
};
