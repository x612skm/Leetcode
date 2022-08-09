class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        //taing all the numbers inside the sum
        for(auto i : nums)
            sum += i;
        
        if(sum&1) return false;
        
        
        int target = sum/2;
        
        //making the matrix
        vector<vector<bool>> dp(nums.size()+1, vector<bool>(target+1));
        
        for(int i=0; i<=nums.size();i++){
            for(int j=0; j<=target;j++){
                //taking the base case
                if(i==0 && j==0)
                    dp[i][j] = true;
                
                else if(j==0 && i!=0)
                    dp[i][j] = true;
                
                else if(i==0 && j!=0)
                    dp[i][j] = false;
                
                //if inputs of the element is less than or equal to the weight
                //formula for the knapsack for pick it or not pick it
                else if(nums[i-1] <= j){
                    dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
                }
                //simply execute the item
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[nums.size()][target];
    }
};