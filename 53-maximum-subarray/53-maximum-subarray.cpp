class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = size(nums);
        int dp[n];
        dp[0] = nums[0];
        
        int maxm = dp[0];
        
        for(int i=1; i<n; ++i){
            int sum = dp[i - 1] > 0 ? dp[i - 1] : 0;
            dp[i] = nums[i] + sum;
            maxm = max(maxm, dp[i]);
            }
        return maxm;
    }
};