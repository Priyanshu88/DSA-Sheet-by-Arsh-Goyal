#include<bits/stdc++.h>
using namespace std;

// use map to store the count of letter
// traverse the string increment the count of letter
// iterate through the map if count is greater than 1 print hr letter

void printDups(string str)
{
    unordered_map<char,int> count;
    for(int i=0;i<str.length();i++)
    {
        count[str[i]]++;     // increase the count of characters by 1
    }

    for(auto it:count)   // iterating through the unordered map
    {
        if(it.second > 1)      // if the count of characters is greater than 1 then duplicate found
        cout << it.first << ", count = " << it.second << "\n";
    }
}

int main()
{
    string str = "LeetCode";
    printDups(str);
    return 0;
}