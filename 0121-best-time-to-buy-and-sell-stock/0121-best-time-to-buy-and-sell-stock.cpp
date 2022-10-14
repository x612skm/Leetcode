class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi =0;
        //int max_so_far = 0;
        int n =prices.size();
        int right = 1;
        int left = 0;
        while(right < prices.size()){
            int curr_profit = prices[right] - prices[left];
            
            if(prices[left] < prices[right]){
                maxi =max(curr_profit, maxi);
            }
            else{
                left = right;
            }
            right++;
        }
        return maxi;
    }
};