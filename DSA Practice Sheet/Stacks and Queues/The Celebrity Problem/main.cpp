// In a party of N people, only one person is known to everyone. Such a person may be present at the party, if yes, (s)he doesn’t know anyone at the party. We can only ask questions like “does A know B? “. Find the stranger (celebrity) in the minimum number of questions.
// We can describe the problem input as an array of numbers/characters representing persons in the party. We also have a hypothetical function HaveAcquaintance(A, B) which returns true if A knows B, and false otherwise. How can we solve the problem?

#include <bits/stdc++.h>
using namespace std;
#define N 4

int celebrity(int M[N][N], int n)
{
    int i = 0, j = n - 1;
    while (i < j)
    {
        if (M[i][j] == 1)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    int candidate = i;
    for (int i = 0; i < n; i++)
    {
        if (i != candidate)
        {
            if (M[i][candidate] == 0 || M[candidate][i] == 1)
                return -1;
        }
    }
    return candidate;
}
int main()
{
    int M[N][N] = {{0, 0, 1, 0},
                   {0, 0, 1, 0},
                   {0, 0, 0, 0},
                   {0, 0, 1, 0}};

    int celebIdx = celebrity(M, 4);

    if (celebIdx == -1)
        cout << ("No Celebrity");
    else
    {
        cout << "Celebrity ID " << celebIdx;
    }
    return 0;
}

// Max # of persons in the party
#define N 8

// Person with 2 is celebrity
bool MATRIX[N][N] = {{0, 0, 1, 0},
                     {0, 0, 1, 0},
                     {0, 0, 0, 0},
                     {0, 0, 1, 0}};

bool knows(int a, int b)
{
    return MATRIX[a][b];
}

int findCelebrity(int n)
{
    stack<int> stk;
    int celebrity;
    for (int i = 0; i < n; i++)
    {
        stk.push(i);
    }
    while (stk.size() > 1)
    {
        int A = stk.top();
        stk.pop();
        int B = stk.top();
        stk.pop();
        if (knows(A, B))
        {
            stk.push(B);
        }
        else
        {
            stk.push(A);
        }
    }
    celebrity = stk.top();
    stk.pop();
    for (int i = 0; i < n; i++)
    {
        if ((i != celebrity) && (knows(celebrity, i) || !knows(i, celebrity)))
        {
            return -1;
        }
    }
    return celebrity;
}

