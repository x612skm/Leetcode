class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //Tc = o(n)
        //sc = O(n)
        unordered_map<int,int>mp;
        int ans = 0;
        for(auto i : nums){
            mp[i]++;
        }
        
        for(auto it : mp){
            if(it.second > 1){
                ans += it.first;
                break;
            }
        }
        return ans;
    }
};