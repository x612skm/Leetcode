class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //we have to look after 3 cases 
        //1. if number more than zero then all zero
        //1. if only one zero
        //2. calculate the product and divide it by the a[i];
        int product = 1; int zeroCount = count(nums.begin(), nums.end(), 0);
        if(zeroCount > 1) return vector<int>(size(nums));
        for(auto n : nums)
            if(n) product*=n;
        
        for(auto& n : nums){
            //there is only a single zero
            if(zeroCount) n = n ? 0 : product; //0 will remain 0 and all will be product
            else
                n = product/n;
        }
        return nums;
    }
};