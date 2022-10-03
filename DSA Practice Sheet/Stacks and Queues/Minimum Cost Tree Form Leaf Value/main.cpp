// 1130. Minimum Cost Tree From Leaf Values
// Medium

// 3490

// 236

// Add to List

// Share
// Given an array arr of positive integers, consider all binary trees such that:

// Each node has either 0 or 2 children;
// The values of arr correspond to the values of each leaf in an in-order traversal of the tree.
// The value of each non-leaf node is equal to the product of the largest leaf value in its left and right subtree, respectively.
// Among all possible binary trees considered, return the smallest possible sum of the values of each non-leaf node. It is guaranteed this sum fits into a 32-bit integer.

// A node is a leaf if and only if it has zero children.

 

// Example 1:


// Input: arr = [6,2,4]
// Output: 32
// Explanation: There are two possible trees shown.
// The first has a non-leaf node sum 36, and the second has non-leaf node sum 32.
// Example 2:


// Input: arr = [4,11]
// Output: 44
 

// Constraints:

// 2 <= arr.length <= 40
// 1 <= arr[i] <= 15
// It is guaranteed that the answer fits into a 32-bit signed integer (i.e., it is less than 231).

#include<bits/stdc++.h>
using namespace std;

// This is a basic Greedy Algorithm.
// We take the least product "element" from its consecutive pairs, remove the element from main array. Also res += its prod.
// (Why consecutive pairs? - becuz the problem says "inorder" array)
// But wait, what happened to the other pair element?
// That's cuz it now becomes useful as the "highest element of the branch" and can be used to check the next minimum prod.
// Proceed until you no longer have two elements.


// We need to keep the sum off the non leaf nodes as low as possible ... So we are first finding the least possible product using the elements at the adjacent indexes .. Add the sum .. Then among the two multipliers , the one which is smaller will never be used .. As clearly mentioned in the description of the problem ..
// For e.g.
// arr[] = [6,2,4]
// sum += (2 X 4) //(sum = 8)... remove 2;
// arr[] = [6,4]
// sum += 6 X 4 //(sum = 32) .. remove 4;
// arr[] = [6]
// STOP .. Cause we need atleast two leaf nodes to form a non leaf node ..
// Hope this helps You.


class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) 
    {

    // Until the size of the array is more than 1;
    // Find the least a[i] * a[i+1] product and accumulate it;
    // Remove the least element which is min of the multipliers

        int sum = 0;
        while(arr.size()>1)
        {
            int min_product = INT_MAX;         // min(a[0]*a[1], ... a[N-1]*a[N])
            int me_index = -1;            // min(a[i], a[i+1])
            for (int i = 1; i < arr.size();i++)
            {
                if(min_product > arr[i-1]*arr[i])
                {
                    me_index = arr[i - 1] < arr[i] ? i - 1 : i;
                    min_product = arr[i - 1] * arr[i];
                }
            }
            sum+=min_product;
            arr.erase(arr.begin() + me_index);
        }
        return sum;
    }
};

// When we build a node in the tree, we compared the two numbers a and b.
// In this process,
// the smaller one is removed and we won't use it anymore,
// and the bigger one actually stays.

// The problem can translated as following:
// Given an array A, choose two neighbors in the array a and b,
// we can remove the smaller one min(a,b) and the cost is a * b.
// What is the minimum cost to remove the whole array until only one left?

// To remove a number a, it needs a cost a * b, where b >= a.
// So a has to be removed by a bigger number.
// We want minimize this cost, so we need to minimize b.

// b has two candidates, the first bigger number on the left,
// the first bigger number on the right.

// The cost to remove a is a * min(left, right).

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) 
    {
        int res = 0;
        vector<int> stack = {INT_MAX};
        for(int i:arr)
        {
            while(stack.back() <= i)
            {
                int mid = stack.back();
                stack.pop_back();
                res += mid * min(stack.back(), i);
            }
            stack.push_back(i);
        }
        for (int i = 2; i < stack.size();i++)
        {
            res += stack[i] * stack[i - 1];
        }
        return res;
    }
};