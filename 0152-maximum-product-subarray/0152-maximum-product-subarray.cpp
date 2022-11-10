class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currmax = nums[0];
        int currmin = nums[0];
        int result = nums[0];
        
        for(int i=1; i<nums.size(); i++){
            int temp = currmax;
            currmax = max(max(currmax*nums[i], currmin*nums[i]), nums[i]);
            currmin = min(min(currmin*nums[i], temp*nums[i]), nums[i]);
            result = max(result, currmax);
        }
        return result;
    }
};