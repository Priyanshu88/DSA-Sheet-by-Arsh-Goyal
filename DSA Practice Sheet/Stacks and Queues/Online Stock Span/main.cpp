// 901. Online Stock Span
// Medium

// 3337

// 235

// Add to List

// Share
// Design an algorithm that collects daily price quotes for some stock and returns the span of that stock's price for the current day.

// The span of the stock's price today is defined as the maximum number of consecutive days (starting from today and going backward) for which the stock price was less than or equal to today's price.

// For example, if the price of a stock over the next 7 days were [100,80,60,70,60,75,85], then the stock spans would be [1,1,1,2,1,4,6].
// Implement the StockSpanner class:

// StockSpanner() Initializes the object of the class.
// int next(int price) Returns the span of the stock's price given that today's price is price.

// Example 1:

// Input
// ["StockSpanner", "next", "next", "next", "next", "next", "next", "next"]
// [[], [100], [80], [60], [70], [60], [75], [85]]
// Output
// [null, 1, 1, 1, 2, 1, 4, 6]

// Explanation
// StockSpanner stockSpanner = new StockSpanner();
// stockSpanner.next(100); // return 1
// stockSpanner.next(80);  // return 1
// stockSpanner.next(60);  // return 1
// stockSpanner.next(70);  // return 2
// stockSpanner.next(60);  // return 1
// stockSpanner.next(75);  // return 4, because the last 4 prices (including today's price of 75) were less than or equal to today's price.
// stockSpanner.next(85);  // return 6

// Constraints:

// 1 <= price <= 105
// At most 104 calls will be made to next.
// Accepted
// 145.1K
// Submissions
// 227.5K

#include <bits/stdc++.h>
using namespace std;

class StockSpanner
{
public:
    stack<int> stk;
    vector<int> vec;
    int i = 0;

    StockSpanner()
    {
    }

    int next(int price)
    {
        vec.push_back(price);
        int res;
        while (!stk.empty() && price >= vec[stk.top()])
            stk.pop();
        res = stk.empty() ? (i + 1) : (i - stk.top());
        stk.push(i++);
        return res;
    }
};

class StockSpanner
{
public:
    stack<int> stk;
    vector<int> vec;
    int i = 0;

    StockSpanner()
    {
    }

    int next(int price)
    {
        vec.push_back(price);
        int res;
        while (!stk.empty() && price >= vec[stk.top()])
            stk.pop();
        if (stk.empty())
        {
            res = i + 1;
        }
        else
        {
            res = i - stk.top();
        }
        stk.push(i++);
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

// Initialize a stack stack. The stack will store elements in the format [price, answer] in a monotonic decreasing manner.

// On each call to next:

// First set ans = 1 representing the answer.
// The top of the stack has a format [priceTop, answerTop]. While priceTop <= price, add answerTop to ans and pop from the stack.
// Push the current [price, ans] onto the stack.
// Return ans.

class StockSpanner
{
public:
    stack<pair<int, int>> st;

    StockSpanner()
    {
    }

    int next(int price)
    {

        // stock span of any day is always atleast one

        int span = 1;
        while (!st.empty() && price >= st.top().first)
        {
            span += st.top().second;
            st.pop();
        }
        st.push({price, span});
        return span;
    }
};

class StockSpanner
{
public:
    stack<pair<int, int>> s;
    int i = 0;

    int next(int price)
    {
        if (s.empty())
        {
            s.push({price, i++});
            return 1;
        }
        else
        {

            // now our stack is not empty so we can eleminate smaller element

            while (!s.empty() && s.top().first <= price)
            {
                s.pop();
            }
            int ans;

            // if our stack is empty so
            if (s.empty())
                ans = i + 1; // case for 105 in [100, 80, 70, 60, 105]
            else
            {
                ans = i - s.top().second;
            }
            s.push({price, i++});
            return ans;
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

class StockSpanner
{
public:
    stack<pair<int, int>> stk;
    StockSpanner()
    {
    }

    int next(int price)
    {
        int span = 1;
        while (!stk.empty() && price >= stk.top().first)
        {
            auto x = stk.top();
            stk.pop();
            int first = x.first;
            int second = x.second;
            span += second;
        }
        stk.push({price, span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */