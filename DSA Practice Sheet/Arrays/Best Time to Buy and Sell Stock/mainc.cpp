class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int min_price = INT_MAX;
    int max_profit = 0;
    for(int i=0;i<n;i++)
    {   

        // buying at lowest price

        min_price = min(min_price,prices[i]);

        // selling at maximum profit

        max_profit =  max(max_profit, prices[i] - min_price);
    }
    return max_profit;
    }
};