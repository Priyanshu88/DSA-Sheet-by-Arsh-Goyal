// 232. Implement Queue using Stacks

// Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

// Implement the MyQueue class:

// void push(int x) Pushes element x to the back of the queue.
// int pop() Removes the element from the front of the queue and returns it.
// int peek() Returns the element at the front of the queue.
// boolean empty() Returns true if the queue is empty, false otherwise.
// Notes:

// You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
// Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.


// Example 1:

// Input
// ["MyQueue", "push", "push", "peek", "pop", "empty"]
// [[], [1], [2], [], [], []]
// Output
// [null, null, null, 1, 1, false]

// Explanation
// MyQueue myQueue = new MyQueue();
// myQueue.push(1); // queue is: [1]
// myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
// myQueue.peek(); // return 1
// myQueue.pop(); // return 1, queue is [2]
// myQueue.empty(); // return false


// Constraints:

// 1 <= x <= 9
// At most 100 calls will be made to push, pop, peek, and empty.
// All the calls to pop and peek are valid.


// Follow-up: Can you implement the queue such that each operation is amortized O(1) time complexity? In other words, performing n operations will take overall O(n) time even if one of those operations may take longer.

#include<bits/stdc++.h>
using namespace std;

class MyQueue {
    public:
        stack<int> s1;
        stack<int> s2;

        // Initialize your data structure here

        MyQueue(){

        }

        // A queue is FIFO (first-in-first-out) but a stack is LIFO (last-in-first-out). 
        // This means the newest element must be pushed to the bottom of the stack. To do so we first transfer all s1 elements to auxiliary stack s2. 
        // Then the newly arrived element is pushed on top of s2 and all its elements are popped and pushed to s1.



        // push element x to the back of queue

        void push(int x)
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            s2.push(x);
            while(!s2.empty())
            {
                s1.push(s2.top());
                s2.pop();
            }
        }

        // Time complexity : O(n).
        // Each element, with the exception of the newly arrived, is pushed and popped twice. The last inserted element is popped and pushed once. Therefore this gives 4 n + 24n+2 operations where nn is the queue size. The push and pop operations have O(1)O(1) time complexity.
        // Space complexity : O(n). We need additional memory to store the queue elements

        // The algorithm pops an element from the stack s1, because s1 stores always on its top the first inserted element in the queue. The front element of the queue is kept as front.
        // removes the element from in front of queue and returns that element

        int pop()
        {
            int res = s1.top();
            s1.pop();
            return res;
        }

        // Time complexity : O(1)
        // Space complexity : O(1)

        // The front element is kept in constant memory and is modified when we push or pop an element.

        // get the front element

        int peek()
        {
            return s1.top();
        }

        // Time complexity : O(1). The front element has been calculated in advance and only returned in peek operation.
        // Space complexity : O(1)

        // Stack s1 contains all stack elements, so the algorithm checks s1 size to return if the queue is empty.
        // returns whether the queue is empty

        bool empty()
        {
            return s1.empty();
        }

        // Time complexity : O(1)
        // Space complexity : O(1)
};



/*  *
    * Your MyQueue object will be instantiated and called as such:
    * MyQueue* obj = new MyQueue();
    * obj->push(x);
    * int param_2 = obj->pop();
    * int param_3 = obj->peek();
    * bool param_4 = obj->empty();
*/


class Solution {
    stack<int> in;
    stack<int> out;

    public:
    MyQueue() 
    {
        
    }

    // push element x to the back of queue

    void push(int x)
    {
        in.push(x);
    }

    // removes the element from in front of queue and returns that element

    int pop()
    {
        if(out.empty())
        {

            // taxing

            while(!in.empty())
            {

                // loading the whole stack in out

                out.push(in.top())
                    in.pop();
            }
        }
        int val = out.top();
        out.pop();
        return val;
    }

    // get the front element

    int peek()
    {
        if(out.empty())
        {

            // taxing

            while(!in.empty())
            {

                // loading the whole stack in out

                out.push(in.top());
                in.pop();
            }
        }
        return out.top();
    }

    // returns whether the queue is empty

    bool empty()
    {
        return out.empty() && in.empty();
    }

};