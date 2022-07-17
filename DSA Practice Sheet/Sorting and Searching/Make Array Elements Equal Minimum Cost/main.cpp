#include<bits/stdc++.h>
using namespace std;


// when all values of array are made equal to X
// minimum cost to make all elements equal

int computeCost(int arr[], int n, int x)
{
    int cost = 0;
    for(int i=0;i<n;i++)
    {
        cost += abs(arr[i] - x);
    }
    return cost;
}


// minimum cost to make all elements equal

int minCost(int arr[], int n)
{
    int low, high;
    low = high = arr[0];

    // setting limits for ternary search by
    // smallest and largest element

    for(int i=0;i<n;i++)
    {
        if(low > arr[i])
        low = arr[i];
        if(high < arr[i])
        high = arr[i];
    }

    // looping until difference between low and high
    // become less than 3, because after that
    // mid1 and mid2 will start repeating

    while((high-low) > 2)
    {

        // mid1 and mid2 are representative array
        // equal values of search space

        int mid1 = low+(high-low)/3;
        int mid2 = high - (high-low)/3;
        int cost1 = computeCost(arr, n, mid1);
        int cost2 = computeCost(arr, n, mid2);

        
        // if mid2 point gives more total cost,
        // skip third part


        if(cost1 < cost2)
        high = mid2;
        
        else
        low = mid1;
    }

     // computeCost gets optimum cost by sending
    // average of low and high as X

    return computeCost(arr, n, (low+high)/2);

}

// T.C.:O(n log n)
// S.C.:O(1)




// this function assumes that a[] is
// sorted. if a[] is not sorted, we need
// to sort it first


int minCostEqual(int arr[], int n)
{
    int y;

    // If there are odd elements, we choose
    // middle element

    if(n%2 == 1)
    {
        y = arr[n/2];
    }

    // if there are even elements, then we choose
    // the average of middle two

    else
    {
        y = (arr[n/2] + arr[(n-2)/2]) / 2;

    }

    // after deciding the final value, finding the result


    int res = 0;

    for(int i=0;i<n;i++)
    {
        res += abs(arr[i] - y);
    }

    return res;

}


// T.C.:O(n)
// S.C.:O(1)



