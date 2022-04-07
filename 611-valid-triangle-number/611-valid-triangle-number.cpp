class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        //sort the nums
        sort(nums.begin(), nums.end());
        int n = nums.size(); int ans = 0;
        
        for(int k=2; k<n; k++) {
            int i = 0, j = k -1; //taking the first second and after that
            
            while(i<j){
                if(nums[i] + nums[j] > nums[k])//triangle rule
                {   ans += j - i;
                   j--;
                }
                else
                {
                    i++;
                }
            }
        }
        return ans;
    }
};