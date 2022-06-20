#include<bits/stdc++.h>
using namespace std;

// Method 1

// void combinationof_r(int arr[],int data[],int start,int end,int index,int r)
// {

//     // print the current combination

//     if(index == r)
//     {
//         for(int j=0;j<r;j++)
//         {
//             cout << data[j] << " ";
//         }
//         cout << endl;
//     }

//     // Replace index with all possible elements and make a combination of the index elements with remaining elements

//     for(int i= start;i<=end && end-i+1 >= r-index;i++)
//     {
//         data[index] = arr[i];
//         combinationof_r(arr,data,i+1,end,index+1,r);
//     }

// }


// void combination(int arr[],int n, int r)
// {
//     // A temporary array to store all combination one by ine
    
//     int data[r];

//     // print all combination using data[]

//     combinationof_r(arr,data,0,n-1,0,r);
// }


// int main()
// {
//     int arr[] = {1,2,3,4,5};
//     int r = 3;
//     int n = 5;
//     combination(arr,n,r);
// }


// Method 2

void combination1(int arr[],int n,int r,int index,int data[],int i)
{

    // print current combination

    if(index == r)
    {
        for(int j =0;j<r;j++)
        {
            cout << data[j] << " ";

        }
        cout << endl;
        return;
    }

    // when no more elements are there to put in data[]

    if(i >= n)
        return;

        // put the next element at next location

        data[index] = arr[i];
        combination1(arr,n,r,index+1,data,i+1);

        // current is excluded, replace it with next (Note that i+1 is passed, but index is not changed)

        combination1(arr,n,r,index,data,i+1);

}


void combination_of_r(int arr[],int n,int r)
{
    
    // to store all combinations

    int data[r];

    // Print all combination using temporary array 'data[]'

    combination1(arr,n,r,0,data,0);
}

int main()
{
    int arr[] = {1,2,3,4,5};
    int r = 3;
    int n = 5;
    combination_of_r(arr,n,r);
    return 0;
}