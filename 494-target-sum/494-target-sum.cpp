class Solution {
public:
    int helper(vector<int>&nums, int n, int target){
        //count the zeroes
        int counter = 0;
        for(int i=0; i<nums.size(); i++)
            if(nums[i] == 0)
                counter++;
        
        int t[n+1][target+1];
        for(int i=0;i<n+1;i++) {
            for(int j=0;j<target+1;j++) {
                if(i==0)
                    t[i][j]=0;
                if(j==0)
                    t[i][j]=1;
            }
        }
        for(int i=1;i<n+1;i++) {
		   //We have to start column from 0 because in this problem we have solve problem if the array contains only 0 .Example; array=[0,0,0,0] and target=0 ,then output would give 16.
            for(int j=0;j<target+1;j++) {
                if(nums[i-1] == 0){
                    t[i][j]=t[i-1][j];
                }
                else if(nums[i-1]<=j) 
                    t[i][j]=t[i-1][j-nums[i-1]] + t[i-1][j];
                else
                    t[i][j]=t[i-1][j];
            }
        }
        return pow(2,counter) * t[n][target];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<nums.size();i++) {
            sum=sum+nums[i];
        }
        if(sum<abs(target) || (sum+target)%2 != 0)
            return 0;
        int remain=(sum+target)/2;
        return helper(nums, nums.size(), remain);
    }
    };