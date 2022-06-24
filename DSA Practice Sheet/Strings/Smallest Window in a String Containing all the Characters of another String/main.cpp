class Solution
{
    public:
    string smallestWindow (string s, string p)
    {

        // if length of string p is greater than string s then we return -1

        if(p.length() > s.length())
        {
            return "-1";
        }
        else
        {

            // using hash tables to store the count of characters in strings

            int shash[26] = {0};
            int phash[26] = {0};

            // storing the count of characters in string p in hash table

            for(int i=0;i<p.length();i++)
            {
                phash[p[i]-'a']++;
            }

            int counter = 0;
            int begin = 0;
            int startindex = -1;
            int length = 0;
            int minlength = INT_MAX;
            for(int i=0;i<s.length();i++)
            {
                
                // storing the count of characters in string s in hash table

                shash[s[i]-'a']++;

                // if count of current character in string s is equal to or 
                // less than in string p, we increment the counter

            }
        }
    }
};