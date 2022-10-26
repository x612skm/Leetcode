class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int,int>mp;
        for(auto& i: nums){
            mp[i]++;
        }
        
        for(auto& it:mp){
            if(it.second > 1)
                ans.push_back(it.first);
            
        }
        return ans;
    }
};