class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int s=0, profit=0;
        for(int i=1; i<prices.size(); i++){
            profit = max(profit, prices[i]-prices[s]);
            if(prices[i] < prices[s])   s=i;
        }
        return profit;
    }
};
