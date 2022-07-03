#include<bits/stdc++.h>
using namespace std;

// Boyer Moore algorithm starts matching from the last character of the pattern
// The character of the text which doesn’t match with the current character of the pattern is called the Bad Character. Upon mismatch, we shift the pattern until 
// mismatch become match i.e. lookup the position of the last occurrence of the mismatched character in the pattern, and if the mismatched character exists in the pattern, then we’ll shift the pattern such that it becomes aligned to the mismatched character in the text T
//  Pattern move past the mismatch character i.e. lookup the position of last occurrence of mismatching character in pattern and if character does not exist we will shift pattern past the mismatching character

#define no_of_char 256

// preprocessing function for boyer moore's algo

void badcharHeuristic(string str,int size, int badChar[no_of_char])
{
    int i;

    // initializing all occurrences as -1
    
    for(i=0;i<no_of_char;i++)
    {
        badChar[i] = -1;
    }

    // fill the actual value of last occurrence of a charater

    for(i = 0;i<size;i++)
    {
        badChar[(int)str[i]] = i;
    }
}


// for pattern searching using bad character heuristic


void Search(string text,string pattern)
{
    int m = pattern.length();
    int n = text.length();

    int badChar[no_of_char];

    // fill the bad character preprocessing function for given function

    badcharHeuristic(pattern,m,badChar);

    // x variable to show the shift of the pattern with respect to text 

    int x = 0;

    while(x <= (n-m))
    {

        int j = m-1;

        // keep reducing index of j of pattern while characters of pattern and text are matching at this shift s

        while( j >= 0 && pattern[j] == text[x+j])
        {
            j--;
        }

        // if the pattern is present at current shift then index j will become -1 after the above loop

        if(j < 0)
        {
            cout << "Pattern occurs at shift = " << x << endl;
            
            // shift the pattern so that the next character in text aligns with the last occurrence of it in pattern.
            // the condition s+m<n is necessary for the case when pattern occurs at the end of text
            
            x += (x + m < n) ? m - badChar[text[x+m]]:1;
        }

        else
        {

            // shift the pattern so that the bad character in text aligns with the last occurrence of it in pattern.
            // the max function is used to make sure that we get a positive shift. but it can be negative shift if last occurrence of bad character in pattern is on right side of current character

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


// T.C.: O(mn)
