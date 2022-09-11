class Solution {
public:
    int numSquares(int n) {
        if(n<=3) return n;
        int * dp = new int[n+1];
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        
        for(int i=4; i<=n; i++){
            dp[i] = i;
            for(int x=1; x<=n;x++){
                int temp = x*x;
                if(temp > i)
                    break;
                else{
                    dp[i] = min(dp[i], 1+ dp[i-temp]);
                }
            }
        }
        int ans = dp[n];
        delete []dp;
        return ans;
    }
};