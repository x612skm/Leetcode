class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto it : nums)
            sum += it;
        
        if(sum % 2)
            return false;
        
        sum /= 2;
        
        vector<bool>dp(sum+1,false);
        
        dp[0] = true;
        
        for(auto it:nums){
            for(int i = sum; i>= it; i--){
                dp[i] = dp[i] || dp[i-it];
            }
        }
        return dp[sum];
    }
};