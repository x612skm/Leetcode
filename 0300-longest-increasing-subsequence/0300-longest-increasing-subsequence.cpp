class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>lis(n+1, 1);
        
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i] > nums[j] and lis[i] < 1 + lis[j])
                    lis[i] = 1+lis[j];
            }
        }
        int ans = 0;
        for(int i=0; i<lis.size(); i++){
            ans = max(lis[i], ans);
        }
        return ans;
    }
};