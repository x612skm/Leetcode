class Solution {
public:
    void helper(vector<int>&nums, int index, vector<int>&pick, vector<vector<int>>& storage){
        storage.push_back(pick);
        for(int j= index; j<nums.size(); j++){
            //will iterate over one by one
            pick.push_back(nums[j]); //pick the first one
            helper(nums,j+1,pick,storage);//execute into the next one for pick/no pick
            pick.pop_back();//empty the pick
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        //given this that all the nums are unique
        vector<int>pick;
        vector<vector<int>> storage;
        helper(nums,0,pick,storage);
        return storage;
    }
};