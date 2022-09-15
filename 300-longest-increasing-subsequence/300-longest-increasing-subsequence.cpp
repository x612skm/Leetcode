class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //there is a pattern to solve the lis
        int n = nums.size();
        vector<int>lis(n+1, 1);
        
        //we make two loops to read the array
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i] > nums[j] and 1+lis[j] > lis[i])
                    lis[i] = 1 + lis[j];
            }
        }
        
        int ans = 0;
        //to stroe the answer
        for(int i=0; i<n; i++){
            ans = max(ans, lis[i]); //this lis[i] is known to have the lis length
            lis.clear();
        }
        return ans;
    }
};