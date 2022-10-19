class Solution {
public:
    int climbStairs(int n) {
        if(n<=3) return n;
        int* dp = new int[n+1];
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        
        for(int i=4; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        int ans = dp[n];
        delete [] dp;
        return ans;
    }
};