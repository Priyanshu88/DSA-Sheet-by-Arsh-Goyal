// Product of Array except itself

// Given an array arr[] of n integers, construct a Product Array prod[] (of same size) such that prod[i] is equal to the product of all the elements of arr[] except arr[i]. Solve it without division operator in O(n) time.

// Example : 

// Input: arr[]  = {10, 3, 5, 6, 2}
// Output: prod[]  = {180, 600, 360, 300, 900}
// 3 * 5 * 6 * 2 product of other array 
// elements except 10 is 180
// 10 * 5 * 6 * 2 product of other array 
// elements except 3 is 600
// 10 * 3 * 6 * 2 product of other array 
// elements except 5 is 360
// 10 * 3 * 5 * 2 product of other array 
// elements except 6 is 300
// 10 * 3 * 6 * 5 product of other array 
// elements except 2 is 900


// Input: arr[]  = {1, 2, 3, 4, 5}
// Output: prod[]  = {120, 60, 40, 30, 24 }
// 2 * 3 * 4 * 5  product of other array 
// elements except 1 is 120
// 1 * 3 * 4 * 5  product of other array 
// elements except 2 is 60
// 1 * 2 * 4 * 5  product of other array 
// elements except 3 is 40
// 1 * 2 * 3 * 5  product of other array 
// elements except 4 is 30
// 1 * 2 * 3 * 4  product of other array 
// elements except 5 is 24

#include<bits/stdc++.h>
using namespace std;


vector<int> productArr(vector<int> &arr)
{
    int size = 0;
    vector<int> res;
    for (int i = 0; i < size;i++)
    {
        int temp = 1;
        for (int j = 0; j < size;j++)
        {
            if(i!=j)
            {
                temp = temp * arr[j];
            }
        }
        res.push_back(temp);
    }
    return res;
}

// Create two extra space, i.e. two extra arrays to store the product of all the array elements from start, up to that index and another array to store the product of all the array elements from the end of the array to that index. 
// To get the product excluding that index, multiply the prefix product up to index i-1 with the suffix product up to index i+1.

// Algorithm: 

// Create two array prefix and suffix of length n, i.e length of the original array, initialize prefix[0] = 1 and suffix[n-1] = 1 and also another array to store the product.
// Traverse the array from second index to end.
// For every index i update prefix[i] as prefix[i] = prefix[i-1] * array[i-1], i.e store the product upto i-1 index from the start of array.
// Traverse the array from second last index to start.
// For every index i update suffix[i] as suffix[i] = suffix[i+1] * array[i+1], i.e store the product upto i+1 index from the end of array
// Traverse the array from start to end.
// For every index i the output will be prefix[i] * suffix[i], the product of the array element except that element.

void ProductArray(int arr[], int n)
{

    // Base case

    if(n==1)
    {
        cout << 0;
        return;
    }

    // Allocate memory for temporary arrays left[] and right[]

    int *left = new int[sizeof(int) * n];
    int *right = new int[sizeof(int) * n];

    // Allocate memory for the product array


    int *prod = new int[sizeof(int) * n];
    int i, j;

    // Left most element of left array is always 1 * /

    left[0] = 1;

    // Right most element of right array is always 1 

    right[n - 1] = 1;

    // Construct the left array

    for (i = 1; i < n;i++)
    {
        left[i] = arr[i - 1] * left[i - 1];
    }

    // Construct the right array

    for (j = n - 2; j >= 0;j--)
    {
        right[j] = arr[j + 1] * right[j + 1];
    }

    // Construct the product array using left[] and right[]

    for (i = 0; i < n;i++)
    {
        prod[i] = left[i] * right[i];
    }

    // print the constructed prod array

    for (int i = 0; i < n;i++)
    {
        cout << prod[i] << " ";
    }
    return;
}


// Store the product of all the elements is a variable and then iterate the array and add product/current_index_value in a new array. and then return this new array.

long* productExceptSelf(int a[],int n)
{
    long prod = 1;
    long flag = 0;

    // product of all elements

    for (int i = 0; i < n;i++)
    {

        // counting number of elements which have value 0

        if(a[i] == 0)
            flag++;
        else
            prod *= a[i];
    }

    // creating a new array of size n

    long *arr = new long[n];

    for (int i = 0; i < n;i++)
    {
        
        // if number of elements in array with value 0 is
        // more than 1 than each value in new array will be
        // equal to 0

        if(flag>1)
            a[i] = 0;

        // if no element having value 0 than we will insert
        // product/a[i] in new array

        else if(flag == 0)
            a[i] = (prod / a[i]);

        // if 1 element of array having value 0 than all the
        // elements except that index value , will be equal
        // to 0

        else if(flag == 1 && a[i] != 0)
            a[i] = 0;
        
        // if(flag == 1 && a[i] == 0)

        else
            a[i] = prod;

    }
    return arr;
}

// T.C.:O(n)
// S.C.:O(1)


// Product array puzzle
// Given an array nums[] of size n, construct a Product Array P (of same size n) such that P[i] is equal to the product of all the elements of nums except nums[i].
// Example 1:
// Input:
// n = 5
// nums[] = {10, 3, 5, 6, 2}
// Output:
// 180 600 360 300 900
// Explanation: 
// For i=0, P[i] = 3*5*6*2 = 180.
// For i=1, P[i] = 10*5*6*2 = 600.
// For i=2, P[i] = 10*3*6*2 = 360.
// For i=3, P[i] = 10*3*5*2 = 300.
// For i=4, P[i] = 10*3*5*6 = 900.
// Example 2:

// Input:
// n = 2
// nums[] = {12,0}
// Output:
// 0 12

// Your Task:
// You do not have to read input. Your task is to complete the function productExceptSelf() that takes array nums[] and n as input parameters and returns a list of n integers denoting the product array P. If the array has only one element the returned list should should contains one value i.e {1}
// Note: Try to solve this problem without using the division operation.

// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(n)

// Constraints:
// 1 <= n <= 1000
// 0 <= nums i <= 200
// Array may contain duplicates.

vector<long long int> productArray(vector<long long int>& nums, int n)
{

    // Allocating the memory and Initialising product array with 1


    vector<long long int> vec(n, 1ll);

    // If all are 1

    if(n == 1)
    {

        // return the vec

        return vec;
    }

    // initializing temp with 1 for left product array value to get stored



    long long temp = 1ll;
    
    // looping from i to n

    for(int i=0;i<n;i++)
    {

        // storing the vec[i] values after multiplying temp


        vec[i] = vec[i] * temp;

        // now storing nums[i] multiplication with temp in temp only


        temp = temp * nums[i];
    }


    // initialising temp with 1 to store the product of values on right side of nums[i]


    temp = 1ll;

    // Looping from right side till 0


    for(int i=n-1;i>=0;i--)
    {
        
        // Multiplying vec[i] with temp and storing in the vec[i]

        
        vec[i] = vec[i] * temp;

        // Multiplying vec[i] with temp and storing the vec[i]


        temp = temp * nums[i];
    }

    // returning the vector

    return vec;
}


class Solution{
    public:

    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) 
    {
        vector<long long int> result;
        long long int product = 1;
        for (long long int i = 0; i < n;i++)
        {
            product *= nums[i];
            result.push_back(product);
        }
        product = 1;
        for (long long int i = n - 1; i >= 0;i--)
        {
            result[i] = result[i - 1] * product;
            product = product * nums[i];
        }
        result[0] = product;
        return result;
    }
};


