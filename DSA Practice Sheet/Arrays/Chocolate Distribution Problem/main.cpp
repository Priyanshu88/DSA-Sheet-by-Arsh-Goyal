#include<bits/stdc++.h>
using namespace std;

int findMinDiff(int arr[],int n, int m)
{

    // number of students and chocolate is 0

    if(m == 0 || n == 0)
    return 0;
    
    // sort the packets

    sort(arr,arr+n);

    // students are more then packet

    if(n < m)
    return -1;

    int min_dif = INT_MAX;

    // Subarray of size m such that difference between last and first elements of subarray is minimum

    for (int i=0;i+m-1<n;i++)
    {
        int diff = arr[i+m-1] - arr[i];
        if(diff < min_dif)
        {
            min_dif = diff;
        }    
    }
    return min_dif;

}

int main()
{
    int arr[] = {12, 4,  7,  9,  2,  23, 25, 41, 30, 40, 28, 42, 30, 44, 48, 43, 50};
    int n = 17;
    int m = 7;
    cout << findMinDiff(arr,n,m);
    return 0;
}