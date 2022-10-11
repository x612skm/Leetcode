class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int, int>mp;
        
        for(int i=0; i<n; i++){
            mp[nums[i]] = i;
        }
        
        for(int i=0; i<n; i++){
            vector<int>temp;
            if(mp.count(nums[i]-1) == 0){
                temp.push_back(nums[i]);
                int t = 1;
                while(mp.count(nums[i] + t)){
                    temp.push_back(nums[i] + t);
                    t++;
                }
                if(temp.size() > ans.size())
                    ans = temp;
            }
            temp.clear();
        }
        return ans.size();
    }
};