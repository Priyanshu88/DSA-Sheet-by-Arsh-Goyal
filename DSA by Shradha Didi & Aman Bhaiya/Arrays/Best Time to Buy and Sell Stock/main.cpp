// 121. Best Time to Buy and Sell Stock

// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

// Example 1:

// Input: prices = [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
// Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
// Example 2:

// Input: prices = [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transactions are done and the max profit = 0.

// Constraints:

// 1 <= prices.length <= 105
// 0 <= prices[i] <= 104

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int profit = 0;
        int Min = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            Min = min(Min, prices[i]);
            profit = max(profit, prices[i] - Min);
        }
        return profit;
    }
};

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() == 0)
            return 0;
        int maxProfit = 0;
        int buyAt = prices[0];
        for (int i = 1; i < prices.size(); i++)
        {
            maxProfit = max(maxProfit, prices[i] - buyAt);
            if (prices[i] < buyAt)
                buyAt = prices[i];
        }
        return maxProfit;
    }
};




// Stock buy and sell

// The cost of stock on each day is given in an array A[] of size N. Find all the days on which you buy and sell the stock so that in between those days your profit is maximum.

// Note: Since there can be multiple solutions, the driver code will return 1 if your answer is correct, otherwise, it will return 0. In case there's no profit the driver code will return the string "No Profit" for a correct solution.

// Example 1:

// Input:
// N = 7
// A[] = {100,180,260,310,40,535,695}
// Output:
// 1
// Explanation:
// One possible solution is (0 3) (4 6)
// We can buy stock on day 0,
// and sell it on 3rd day, which will
// give us maximum profit. Now, we buy
// stock on day 4 and sell it on day 6.
// Example 2:

// Input:
// N = 5
// A[] = {4,2,2,2,4}
// Output:
// 1
// Explanation:
// There are multiple possible solutions.
// one of them is (3 4)
// We can buy stock on day 3,
// and sell it on 4th day, which will
// give us maximum profit.

// Your Task:
// The task is to complete the function stockBuySell() which takes an array A[] and N as input parameters and finds the days of buying and selling stock. The function must return a 2D list of integers containing all the buy-sell pairs i.e. first value of pair will represent the day on which you buy the stock and second value represent the day on which you sell that stock. If there is No Profit, return an empty list.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)

// Constraints:
// 2 ≤ N ≤ 106
// 0 ≤ A[i] ≤ 106

class Solution
{
public:
    vector<vector<int>> stockBuySell(vector<int> A, int n)
    {
        vector<vector<int>> x;
        for (int i = 1; i < n; i++)
        {
            if (A[i] > A[i - 1])
            {
                x.push_back({i - 1, i});
            }
        }
        return x;
    }
};



class Solution
{
public:
    vector<vector<int>> stockBuySell(vector<int> A, int n)
    {
        int bought = A[0];
        int buyDay = 0;
        vector<vector<int>> ans;
        for (int i = 1; i < n; i++)
        {
            if (A[i] > bought)
            {
                ans.push_back({buyDay, i});
                buyDay = i;
                bought = A[i];
            }
            else if (A[i] < bought)
            {
                buyDay = i;
                bought = A[i];
            }
        }
        return ans;
    }
};