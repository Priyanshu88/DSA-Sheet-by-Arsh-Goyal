class Solution {
public:
    int maxProfit(vector<int>& prices) {
    int profit = 0;

    // keep on adding the difference between the consecutive numbers of the array if the second number is larger than the first one, then total sum will be the maximum profit.

    for (int i=1;i<prices.size();i++)
    {
        if(prices[i] > prices[i-1])
        {
            profit = profit + prices[i] - prices[i-1];
        }
    }
        return profit;
    }
};