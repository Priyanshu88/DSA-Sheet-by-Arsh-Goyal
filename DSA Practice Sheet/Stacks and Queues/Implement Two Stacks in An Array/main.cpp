// Implement two stacks in an array

// Difficulty Level : Easy
// Last Updated : 04 Jul, 2022
// Create a data structure twoStacks that represents two stacks. Implementation of twoStacks should use only one array, i.e., both stacks should use the same array for storing elements. 

// Following functions must be supported by twoStacks.

// push1(int x) –> pushes x to first stack 
// push2(int x) –> pushes x to second stack
// pop1() –> pops an element from first stack and return the popped element 
// pop2() –> pops an element from second stack and return the popped element
// Implementation of twoStack should be space efficient.

// Method 1 (Divide the space in two halves):

// A simple way to implement two stacks is to divide the array in two halves and assign the half space to two stacks, i.e., 
// use arr[0] to arr[n/2] for stack1, and arr[(n/2) + 1] to arr[n-1] for stack2 where arr[] is the array to be used to implement two stacks and size of array be n. 
// The problem with this method is inefficient use of array space. A stack push operation may result in stack overflow even if there is space available in arr[]. 
// For example, say the array size is 6 and we push 3 elements to stack1 and do not push anything to second stack2. When we push 4th element to stack1, t
// here will be overflow even if we have space for 3 more elements in array.


#include<bits/stdc++.h>
using namespace std;

class twoStacks {
    int *arr;
    int size;
    int top1, top2;

    public:

    // constructor

    twoStacks(int n)
    {
        size = n;
        arr = new int[n];
        top1 = n / 2 + 1;
        top2 = n / 2;
    }

     // Method to push an element x to stack1

    void push1(int x)
    {

        // there is atleast one empty
        // space fot new element

        if(top1 > 0)
        {
            top1--;
            arr[top1] = x;

        }
        else
        {
            cout << "Stack overflow" << "By element:" << x << endl;
            return;
        }

    }

    // Method to push an element x to stack2


    void push2(int x)
    {

        // There is at least one empty space for new element

        if(top2 < size-1)
        {
            top2++;
            arr[top2] = x;
        }
        else

        {
            cout << "Stack overflow" << "By element:" << x << endl;
            return;
        }
    }

    // Method to pop an element from first stack

    int pop1()
    {
        if(top1<=size/2)
        {
            int x = arr[top1];
            top1++;
            return x;
        }
        else
        {
            cout << "Stack overflow";
            exit(1);
        }
    }

    // Method to pop an element from second stack

    int pop2()
    {
        if(top2 >size/2+1)
        {
            int x = arr[top2];
            top2--;
            return x;
        }
        else
        {
            cout << "Stack overflow";
            exit(1);
        }
    }

};

// T.C.:O(1)
// S.C.:O(n)



// Method 2 (A space efficient implementation) :
// This method efficiently utilizes the available space. It doesn’t cause an overflow if there is space available in arr[]. 
// The idea is to start two stacks from two extreme corners of arr[]. stack1 starts from the leftmost element, the first element in stack1 is pushed at index 0. 
// The stack2 starts from the rightmost corner, the first element in stack2 is pushed at index (n-1). Both stacks grow (or shrink) in opposite direction. 
// To check for overflow, all we need to check is for space between top elements of both stacks. This check is highlighted in the below code. 


class twoStacks {
    int *arr;
    int size;
    int top1, top2;

    public:

    // constructor

    twoStacks(int n)
    {
        size = n;
        arr = new int[n];
        top1 = -1;
        top2 = size;
    }

    // Method to push an element x to stack1

    void push1(int x)
    {

        // There is at least one empty space for new element

        if(top1<top2-1)
        {
            top1++;
            arr[top1] = x;
        }
        else
        {
            cout << "Stack overflow";
            exit(1);
        }
    }

    // Method to push an element x to stack2

    void push2(int x)
    {

        // There is at least one empty
        // space for new element

        if(top1<top2-1)
        {
            top2--;
            arr[top2] = x;

        }
        else
        {
            cout << "Stack overflow";
            exit(1);
        }

    }

    // Method to pop an element from first stack

    int pop1()
    {
        if(top1>=0)
        {
            int x = arr[top1];
            top1--;
            return x;
        }
        else
        {
            cout << "Stack overflow";
            exit(1);
        }
    }

    int pop2()
    {
        if(top2<size)
        {
            int x = arr[top2];
            top2++;
            return x;
        }
        else
        {
            cout << "Stack underflow";
            exit(1);
        }
    }

};

// Implement two stacks in an array
// EasyAccuracy: 49.76%Submissions: 89105Points: 2
// Your task is to implement  2 stacks in one array efficiently.



// Example 1:

// Input:
// push1(2)
// push1(3)
// push2(4)
// pop1()
// pop2()
// pop2()

// Output:
// 3 4 -1

// Explanation:
// push1(2) the stack1 will be {2}
// push1(3) the stack1 will be {2,3}
// push2(4) the stack2 will be {4}
// pop1()   the poped element will be 3 
// from stack1 and stack1 will be {2}
// pop2()   the poped element will be 4 
// from stack2 and now stack2 is empty
// pop2()   the stack2 is now empty hence -1 .


// Your Task:
// You don't need to read input or print anything. You are required to complete the 4 methods push1, push2 which takes one argument an integer 'x' to be pushed into stack one and two and pop1, pop2 which returns the integer poped out from stack one and two. If no integer is present in the array return -1.


// Expected Time Complexity: O(1) for all the four methods.
// Expected Auxiliary Space: O(1) for all the four methods.



// Constraints:
// 1 <= Number of queries <= 100
// 1 <= Number of elements in the stack <= 100
// The sum of elements in both the stacks < size of the given array


//Function to push an integer into the stack1.

void twoStacks :: push1(int x)
{
    top1++;
    arr[top1] = x;
}

//Function to push an integer into the stack2.

void twoStacks ::push2(int x)
{
    top2--;
    arr[top2] = x;
}

//Function to remove an element from top of the stack1.

int twoStacks ::pop1()
{
    if(top1 == -1)
    {
        return -1;
    }
    else
    {
        return arr[top1--];
    }
}

//Function to remove an element from top of the stack2.
int twoStacks :: pop2()
{
    if(top2==size)
    {
        return -1;
    }
    else 
    {
        return arr[top2++];
    }
}