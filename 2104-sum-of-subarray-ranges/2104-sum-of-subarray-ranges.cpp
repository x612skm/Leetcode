class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long res = 0;
        for(int i=0; i<nums.size(); i++){
            int maxm = nums[i], minm = nums[i];
            for(int j =i; j<nums.size(); j++){
                maxm = max(maxm, nums[j]);
                minm = min(minm, nums[j]);
                
                res += maxm - minm;
            }
        }
        return res;
    }
};