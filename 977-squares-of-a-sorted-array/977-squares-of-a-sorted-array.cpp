class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res(nums.size()); // result vctor of nums size
        int start = 0, end = nums.size()-1;
        
        for(int k = end ; k >= 0; k--){
            if(abs(nums[end]) > abs(nums[start]))
                res[k] = nums[end] * nums[end--];
            else
                res[k] = nums[start] * nums[start++];
        }
        return res;
    }
};