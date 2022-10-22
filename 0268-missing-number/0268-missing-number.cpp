class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
//         for(int i=0; i<n; i++){
//             if(n<=2 and nums[i] != n)
                
//         }
        if(nums[n-1] != n)
            return n;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != i)
                return i;
        }
        return -1;
    }
};