class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //we have to check 3 cases 
        // 1.zero count 
        // 2.product
        // 3.division by nums[i];
        
        int product = 1; 
        int zeroCount = count(nums.begin(), nums.end(), 0);
        if(zeroCount > 1) return vector<int> (size(nums));
        for(auto& n : nums){
            if(n)
                product *= n;
        }
        
        for(auto& n : nums){
            if(zeroCount) //if there's only one zero
                n = n ? 0 : product;
            else
                n = product/n;
        }
        return nums;
    }
};