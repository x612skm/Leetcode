class Solution {
private:
    //using the backtraking format
    void dfs(vector<int>& nums, int pos, vector<vector<int>>& ans){
        if(pos == nums.size())
        {
            ans.push_back(nums);
            return;
        }
        
        for(int i=pos; i<nums.size(); i++){
            swap(nums[pos], nums[i]);
            dfs(nums,pos+1,ans);
            swap(nums[pos], nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
         vector<vector<int>> ans;
        dfs(nums, 0, ans);
        return ans;
    }
};