class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int max_i =0;
        vector<int> dp(n,1);
        vector<int> pred(n,-1);
        
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i] % nums[j] == 0 and dp[i] < 1+dp[j]){
                    dp[i] = 1 + dp[j];
                    pred[i] = j;
                }
                if(dp[i] > dp[max_i])
                    max_i = i;
            }
        }
        vector<int>ans;
        for(; max_i >=0; max_i=pred[max_i])
            ans.push_back(nums[max_i]);
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};