class Solution {
public:
    int fib(int n) {
        if(n < 2) return n;
        
        int dp[n+1];

        //storing the data 
        //memozied version of the dp
        dp[0] = 0;
        dp[1] = 1;
        
        //we will start with the next tree
        for(int i=2; i<=n; ++i){
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};