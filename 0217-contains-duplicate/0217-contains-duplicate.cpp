class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, bool> mp; //tc o(1) for the hash set operation
        for(int i=0; i<n; i++){
            if(mp.count(nums[i]) > 0){
                return true;
            }
            mp[nums[i]] = true;
        }
        return false;
    }
};