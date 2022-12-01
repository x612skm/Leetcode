class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        int countzero = count(nums.begin(), nums.end(), 0);
        if(countzero > 1) return vector<int> (nums.size());
        
        for(auto& it : nums){
            if(it)
                product *= it;
        }
        
        for(auto& it: nums){
            if(countzero)
                it = it ? 0 : product;
            else{
                it = product/it;
            }
        }
        return nums;
    }
};