class Solution {
public:
    int findLow(vector<int>& coins, int arrSize, int amount){
        //there are only two changes one in initilisation
        //one in the conditoin from the coin change problem
        // Initializing first column of array to 1
        // because a sum of 0 can be made
        // in one possible way: {0}
        // Initializing first row of array to 0
        // because a sum cannot be made with no coins:
        int dp[arrSize + 1][amount+1];
        //initilise the matrix
        for(int i=0; i< arrSize+ 1; i++){
            for(int j=0; j< amount + 1; j++){
                if(i==0)
                    dp[i][j] = 0;
                if(j==0)
                    dp[i][j] = 1;
                    // to avoid the overflow
            }
        }
        
        for(int i=1; i<arrSize+1; i++){
            for(int j=1; j<amount+1; j++){
                if(coins[i-1] <= j)
                    dp[i][j] =  dp[i-1][j] + dp[i][j-coins[i-1]] ;
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[arrSize][amount];
        
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        return findLow(coins,n,amount);
    }
};