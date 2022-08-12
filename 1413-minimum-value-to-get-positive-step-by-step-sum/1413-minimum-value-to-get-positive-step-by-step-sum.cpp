class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int ans = 0, minSum = 0;
        for(int i=0; i<nums.size(); i++){
            minSum += nums[i];
            ans = min(ans, minSum);
        }
        
        return 1 - ans;
    }
};