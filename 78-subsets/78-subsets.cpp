class Solution {
private:
    void findSubset(vector<int>& nums, int index, vector<int>&sub, vector<vector<int>>& subs){
        subs.push_back(sub);
        for(int j=index; j<nums.size(); j++){
            sub.push_back(nums[j]);
            findSubset(nums, j+1, sub, subs);
            sub.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> sub;
        vector<vector<int>> subs;
        findSubset(nums,0, sub, subs);
        return subs;
    }
};