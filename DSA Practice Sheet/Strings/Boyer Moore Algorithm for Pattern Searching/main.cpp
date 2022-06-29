#include<bits/stdc++.h>
using namespace std;

#define no_of_char 256

void badcharHeuristic(string str,int size, int badChar[no_of_char])
{
    int i;

    for(i=0;i<no_of_char;i++)
    {
        badChar[i] = -1;
    }

    for(i = 0;i<size;i++)
    {
        badChar[(int)str[i]] = i;
    }
}



void Search(string text,string pattern)
{
    int m = pattern.length();
    int n = text.length();

    int badChar[no_of_char];
    badcharHeuristic(pattern,m,badChar);
    int x = 0;

    while(x <= (n-m))
    {
        int j = m-1;

        while( j >= 0 && pattern[j] == text[x+j])
        {
            j--;
        }

        if(j < 0)
        {
            cout << "Pattern occurs at shift = " << x << endl;
            x += (x + m < n) ? m - badChar[text[x+m]]:1;
        }

        else
        {
            x += max(1, j-badChar[text[x+j]]);
        }
    }
}


int main()
{
    string text = "ABAAABCD";
    string pattern = "ABC";
    Search(text,pattern);
    return 0;
}
