class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if( n == 0) return 0;
        
        int imin = nums[0];
        int imax = nums[0];
        int result = nums[0];
        
        for(int i=1; i<n; i++){
            if(nums[i] < 0)
                swap(imax,imin);
            int temp_max = max(nums[i] * imax, max(nums[i] * imax, nums[i]));
            imin = min(nums[i] * imax, min(nums[i] * imin, nums[i]));
            imax = temp_max;
            result = max(result, imax);
        }
        return result;
    }
};