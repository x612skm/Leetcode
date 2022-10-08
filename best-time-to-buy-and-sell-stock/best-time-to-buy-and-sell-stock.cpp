class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //using kadanes algorithm 
        int maxPro = 0;
        int minPri = INT_MAX;
        for(int i=0; i<prices.size(); i++){
            minPri = min(minPri, prices[i]);
            maxPro = max(maxPro, prices[i] - minPri);
        }
        return maxPro;
    }
};