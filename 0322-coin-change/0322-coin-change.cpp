class Solution {
public:
    int dp[12+1][10000+1]; //making from the constraints
    int uknap(vector<int>&coins, int value, int amount){
        //this is a variation of unbounded knapsack
        //initilise the matrix
        for(int i=0; i<value+1; i++){
            for(int j=0; j<amount+1; j++){
                if(i==0 or j==0)
                    dp[i][j] = (j==0) ? 0 : INT_MAX-1;
            }
        }
        //now the code for the variation
        //since this is a take and again take conditon
        //we can take the coin again
        for(int i=1; i<value+1; i++){
            for(int j=1; j<amount+1; j++){
                if(coins[i-1] <= j)
                    dp[i][j] = min(dp[i-1][j],1+dp[i][j-coins[i-1]]);
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        
        return dp[value][amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        int value = coins.size();
        int ans = uknap(coins,value,amount);
        return (ans == INT_MAX-1) ? -1 : ans;
    }
};