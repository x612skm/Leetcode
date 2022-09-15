class Solution {
public:
    int dp[12+1][10000+1];
    int findLow(vector<int>& coins, int arrSize, int amount){
        //initilise the matrix
        for(int i=0; i<arrSize + 1; i++){
            for(int j=0; j<amount+1; j++){
                if(i ==0 || j ==0)
                    dp[i][j] = (j==0) ? 0 : INT_MAX -1; // to avoid the overflow
            }
        }
        
        for(int i=1; i<arrSize+1; i++){
            for(int j=0; j<amount+1; j++){
                if(coins[i-1] <= j)
                    dp[i][j] = min(dp[i-1][j], 1+dp[i][j-coins[i-1]]);
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[arrSize][amount];
        
    }
    int coinChange(vector<int>& coins, int amount) {
        int res = findLow(coins, coins.size(),amount);
        return (res == INT_MAX-1) ? -1:res; 
    }
};