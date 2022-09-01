#include<bits/stdc++.h>
using namespace std;

// if x is smaller than or equal to first element then returning the index of first element
// otherwise searching for index such that if x is equal to a[i]then return i  and if x lies between a[i] and a[i+1] including a[i+1] 
// then return i+1

int ceilSearch (int a[],int low, int high, int x)
{
    if(x <= a[low])
    return low;

    for(int i=low;i<high;i++)
    {
        if(a[i] == x)
        return i;
    
        if(a[i] < x && a[i+1] >= x)
        return i+1;
    }

    // if x is greater than the element of the array return -1 
    
    return -1;
}




// if x is smaller than first element then returning -1 as floor does not exist
// otherwise searching for index such that if x is equal to a[i] then return i and if x is greater than a[i] and a[i+1] is greater than or equal to x
// then return i else return -1




int floorSearch(int a[], int low, int high, int x)
{
    if(x < a[low])
    return -1;

    for(int i=low;i<high;i++)
    {
        if(a[i] == x)
        return i;
        if(a[i] < x && a[i+1] >= x)
        return i;
    }
    return -1;
}


// T.C.: O(n)


#include <bits/stdc++.h>
using namespace std;

// binary search
// if the length of arr == 0 then return -1
// this while loop function will run until
// condition not break once condition break
// loop will return start and ans is low
// which will be next smallest greater than target
// which is ceiling
// finding middle element if x is equal to arr[mid] return mid, if x is less than arr[mid] then set high as mid-1
// else set low as mid+1
// once condition breaks at(low <= high) return low which is my ceiling of  target.


int ceilSearch(int arr[], int low, int high, int x)
{
    if(x == 0)
    {
        return -1;

    }

    while(low <= high)
    {
        int mid = low + (high-low)/2;
        if(arr[mid] == x)
        {
            return mid;
        }

        else if(x < arr[mid])
        {
            high = mid-1;
        }

        else 
        {
            low = mid+1;
        }
    }
    return low;
}

// T.C.:O(log n)