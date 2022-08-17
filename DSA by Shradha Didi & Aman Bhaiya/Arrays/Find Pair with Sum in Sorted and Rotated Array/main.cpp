// Find if there is a pair with a given sum in the rotated sorted Array

// Difficulty Level : Medium

// Given an array arr[] of distinct elements size N that is sorted and then around an unknown point, the task is to check if the array has a pair with a given sum X.

// Examples : 

// Input: arr[] = {11, 15, 6, 8, 9, 10}, X = 16
// Output: true
// Explanation: There is a pair (6, 10) with sum 16

// Input: arr[] = {11, 15, 26, 38, 9, 10}, X = 35
// Output: true
// Explanation: There is a pair (26, 9) with sum 35

// Input: arr[] = {11, 15, 26, 38, 9, 10}, X = 45
// Output: false
// Explanation: There is no pair with sum 45


// First find the largest element in an array which is the pivot point also and the element just after the largest is the smallest element. Once we have the indices of the largest and the smallest elements, we use a similar meet-in-middle algorithm (as discussed here in method 1) to find if there is a pair. 
// The only thing new here is indices are incremented and decremented in a rotational manner using modular arithmetic.

// Illustration:

// Let us take an example arr[]={11, 15, 6, 8, 9, 10}, sum=16.
// pivot = 1,  

// l = 2, r = 1:
//         => arr[2] + arr[1] = 6 + 15 = 21 which is > 16 
//         => So decrement r circularly. r = ( 6 + 1 – 1) % 6, r = 0

// l = 2, r = 0:
//         => arr[2] + arr[0] = 17 which is > 16. 
//         => So decrement r circularly. r = (6 + 0 – 1) % 6, r = 5

// l = 2, r = 5:
//         => arr[2] + arr[5] = 16 which is equal to 16. 
//         => Hence return true

// Hence there exists such a pair.

// Follow the steps mentioned below to implement the idea:

// We will run a for loop from 0 to N-1, to find out the pivot point. 
// Set the left pointer(l) to the smallest value and the right pointer(r) to the highest value.
// To restrict the circular movement within the array we will apply the modulo operation by the size of the array.
// While l ! = r, we shall keep checking if arr[l] + arr[r] = sum.
// If arr[l] + arr[r] is greater than X, update r = (N+r-1) % N.
// If arr[l] + arr[r] is less than X, update l = (l+1) % N.
// If arr[l] + arr[r] is equal to the value X, then return true.
// If no such pair is found after the iteration is complete, return false.


#include<bits/stdc++.h>
using namespace std;


bool PairInSortedRotated(int arr[], int n, int x)
{
    int i = 0;
    for (i = 0; i < n;i++)
    {
        if(arr[i] > arr[i+1])
            break;
    }

    int l = (i + 1) % n;

    int r = i;

    while(l != r)
    {
        if(arr[l] + arr[r] == x)
        {
            return true;
        }

        if(arr[l] + arr[r] < x)
        {
            l = (l + 1) % n;
        }

        else
            r = (n - r + 1) % n;
    }
    return false;
}