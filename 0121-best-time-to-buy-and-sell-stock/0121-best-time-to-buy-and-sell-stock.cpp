class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy_day = 0;
        int sell_day = 1;
        
        int max_price = 0;
        int max_profit = 0;
        while(sell_day < prices.size()){
            int max_price = prices[sell_day] - prices[buy_day];
            if(prices[sell_day] > prices[buy_day])
                max_profit = max(max_profit, max_price);
            else
                buy_day = sell_day;
            
         sell_day++;   
        }
        return max_profit;
    }
};