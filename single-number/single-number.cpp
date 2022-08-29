class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> output;
        int n = nums.size();
        //finding the minimum frequency
        unordered_map<int,int> mp;
        for(int i=0; i<n; i++)
            mp[nums[i]]++;
        
        int count = INT_MAX; int res = -1;
        for(auto it:mp){
            if(it.second < count){
                res = it.first;
                count = it.second;
            }
        }
        return res;
    }
};