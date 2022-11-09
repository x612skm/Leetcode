class Solution {
private:
    int robber(vector<int>&nums, int start, vector<vector<int>>&output){
        if(start < 0)
            return 0;
        int n = nums.size();
        
        if(output[n][start] != -1)
            return output[n][start];
        
        output[n][start] = max(robber(nums, start-1, output), robber(nums, start-2, output)+nums[start]);
            return output[n][start];
    }
public:
    int rob(vector<int>& nums) {
        int n =nums.size();
        vector<vector<int>> vec( 501 , vector<int> (501, -1));
        return robber(nums, n-1, vec);
        
    }
};