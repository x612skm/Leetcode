class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        //vector<int> ans(n,0);
        for(int i=0; i<nums.size(); i++){
            nums[i] = pow(nums[i],2);
            
        }
        sort(nums.begin(), nums.end());
        return nums;
    }
};