class Solution {
private:
    void dfs(vector<int>&nums, int position, vector<vector<int>>& ans){
        if(position == nums.size())
            ans.push_back(nums);
        else{
            for(int i=position; i<nums.size(); i++){
                swap(nums[i], nums[position]);
                dfs(nums, position+1, ans);
                swap(nums[i], nums[position]);
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        dfs(nums, 0 , ans);
        
        return ans;
    }
};