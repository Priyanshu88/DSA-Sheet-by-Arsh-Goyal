class Solution {
public:

    // bring the words out of the string and keep inserting at the starting of new string

    string reverseWords(string s) 
    {
        string ans = "";
        int i,j,n=s.length();
        i=0;
        while(i<n)
        {

            // do not include leading spaces

            while(i<n && s[i] == ' ')
            i++;
            j=i;

            // till when we do not reach a space, means we are currently on a word

            while(j<n && s[j] != ' ')
            j++;

            // here j is pointing to the next index of the ending of the current word, due to this when passing length as 2nd parameter in substr function, we pass j-i not j-i+1  

            ans = " " + s.substr(i,j-i)+ans;
            i=j+1;
        }

        // remove leading spaces

        i=0;
        while(i<n && ans[i] == ' ')
        i++;
        ans = ans.substr(i);
        return ans;
    }
};


// Reversing whole string again maintaining two indices i and j for starting and ending of word,
// i will not point to starting of word but instead to first first leading space
// Reason for the same is when we will call reverse on i..j, It will bring word in the front and spaces to the back, In this way we will make all space to the trailing ones.
// we will rev(i,j) when i==0 because there might not be a single space, For other cases it is clearly mentioned that there will be at least 1 space between words.

class Solution {
public:
    void rev(string &s,int l,int r)
    {
        while(l<r)
        {
            swap(s[l++],s[r--]);
        }
    }
    string reverseWords(string s) 
    {
        int i,j,n = s.length();
        i = 0;
        rev(s,0,n-1);
        while(i<n)
        {

            // remove leading spaces

            j=i;
            while(j<n && s[j] == ' ')
            j++;

            int cnt = 0;

            while(j<n && s[j] != ' ')
            {
                j++;
                cnt++;
            }

            if(cnt == 0)
            break;
            j--;

            if(i==0)
            rev(s,i,j);
            else
            rev(s,i+1,j);
            if(cnt == 0)
            i = j+1;
            else
            i = i+cnt;
            
        }

        j = n-1;
        while(j>=0 && s[j]==' ')
        {
            j--;
            s.pop_back();

        }
        return s;
    }
};


class Solution {
public:
    string reverseWords(string s) 
    {
        vector<string> vec;
        stringstream str(s);
        string word;
        while(str >> word)  // store separated words in vector
        vec.push_back(word);
        reverse(vec.begin(),vec.end());  // reverse vector

        string res;
        for(const auto &it:vec) // concatenate strings
        res+=" "+it;
        res.erase(0,1); // first place is always a space extra
        return res;
    }
};