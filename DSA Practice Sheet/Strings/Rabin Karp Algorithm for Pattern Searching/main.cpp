#include <bits/stdc++.h>
using namespace std;

// number of characters in input alphabet

#define d 256

// pat -> pattern
// txt -> text
// q -> a prime number

void RKSearch(string pat,string txt,int q)
{
    int m = pat.length();
    int n = txt.length();
    int h = 1;
    int p = 0;              // hash value for pattern
    int t = 0;              // hash value for text
    int j;

    // The value of h would be "pow(d,m-1)%q"


    for(int i = 0;i < m-1;i++)
    h = (h*d) % q;

    // hash value of pattern and
    // hash value of first window of text

    for(int i=0;i < m;i++)
    {
        p = (d*p + pat[i])%q;
        t = (d*t + txt[i])%q;
    }

    // slide the pattern over text one by one

    for(int i=0; i<= n-m;i++)
    {

        // check the hash values of current window of tet and pattern
        // if hash values match then only check for characters one by one

        if(p == t)
        {

            // check for characters one by one

            for(j = 0;j < m;j++)
            {
                if(txt[i+j] != pat[j])
                {
                    break;
                }
            }
            
            // if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1] 

            if(j == m)
            {
                cout << "Pattern found at index " << i << endl;
            }
        }
        if(i < n-m)
        {

            // calculating hash value for next window of text: remove leading digit and add trailing digit

            t = (d*(t - txt[i]*h) + txt[i + m]) % q;

            // converting negative value of t to positive

            if(t < 0)
            t = (t + q);
            
        }
    }
}

int main()
{
    string txt = "GEEKS FOR GEEKS";
    string pat = "GEEK";

    // mod is done to avoid overflowing of value but it should take as big q as possible to avoid the collision

    int q = INT_MAX;
    RKSearch(pat,txt,q);
    return 0;
}




