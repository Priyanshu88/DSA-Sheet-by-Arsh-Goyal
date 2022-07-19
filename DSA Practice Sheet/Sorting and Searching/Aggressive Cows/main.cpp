#include <bits/stdc++.h>
using namespace std;


// firstly sorting the array and setting minimum distance then keep on increasing
// it until accommodation of all cows is not possible. we stop just before that to get our answer after maximizing it with d
// for checking if the cows can fit or not, simply iterating over our n stalls, and for every stall with the said minimum distance, 
// placing our cow. After it is done, if all cows have been accommodated, returning true, otherwise false.


bool isCompatible(vector<int> &inP, int dist, int cows)
{
    int n = inP.size();
    int k = inP[0];
    cows--;
    for(int i=1;i<n;i++)
    {
        if(inP[i] - k >= dist)
        {
            cows--;
            if(!cows)
            {
                return true;
            }

            k = inP[i];
        }
    }
    return false;
}


int main() 
{
    int n = 5, m = 3;
    vector<int> inP{1,2,8,4,9};
    sort(inP.begin(),inP.end());
    int maxD = inP[n-1] - inP[0];
    int ans = INT_MIN;
    for(int d=1;d<=maxD;d++)
    {
        bool possible = isCompatible(inP, d, m);
        if(possible)
        {
            ans = max(ans, d);
        }
    }

    cout << "The largest minimum difference is " << ans << "\n";
}


// T.C.:O(n * m)
// S.C.:O(1)


// sorting the array first and setting low = 1 because the minimum distance is 1 and high = array[n-1] – array[0] . because that’s the 
// maximum possible distance between two stalls calculating our mid-value after this. 
// mid = low + (high-low)/2
// Then checking if the minimum distance (mid-value) is possible by the same method defined in brute force, 
// and if it is not possible, then setting our upper bound as high-1, and if it is possible, storing it in an answer variable and setting
// our lower bound as mid+1. and doing this until high and low pointers are equal. 



#include<bits/stdc++.h>
using namespace std;


bool isPossible(int arr[], int n, int cows, int minDist)
{
    int cntCows = 1;
    int lastPlaceCow = arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i] - lastPlaceCow >= minDist)
        {
            cntCows++;
            lastPlaceCow = arr[i];
        }
    }

    if(cntCows >= cows) return true;
    return false;
}


int main()
{
    int n = 5, cows = 3;
    int arr[] = {1,2,8,4,9};
    sort(arr,arr+n);

    int low = 1, high = arr[n-1] - arr[0];

    while(low <= high)

    {
        int mid = (low + high) >> 1;

        if(isPossible(arr,n, cows, mid))
        {
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
    }

    cout << "The largest minimum distance is " << high << endl;

    return 0;

}



// T.C.:O(n log m)
// S.C.:O(1)
