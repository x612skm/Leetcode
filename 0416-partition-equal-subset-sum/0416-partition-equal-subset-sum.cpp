class Solution {
//private:
    //int dp[201][101];
public:
    bool canPartition(vector<int>& nums) {
        //this is a variation of knapsack 0/1
        //[1,5,5,11] we can take or we cannot take
        int sum = 0;
        for(auto i: nums)
            sum += i;
        
        if(sum&1) return false; //remainder is 1 and sum is odd partion not possible
        int target = sum/2;
        
        //vector<vector<bool>>dp(nums.size()+1, vector<bool>(target+1));
        vector<vector<bool>> dp(nums.size()+1, vector<bool>(target+1));
        
        for(int i=0; i<=nums.size(); i++){
            for(int j=0; j<=target; j++){
                if(i==0 and j==0)
                    dp[i][j] = true;
                 else if(j==0 && i!=0)
                    dp[i][j] = true;
                
                else if(i==0 && j!=0)
                    dp[i][j] = false;
            }
        }
        
        for(int i=1; i<=nums.size(); i++){    
                //take it or not take it
            for(int j=1; j<=target; j++){
                if(nums[i-1] <= j)
                    dp[i][j] = dp[i-1][j-nums[i-1]] or dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[nums.size()][target];
    }
};