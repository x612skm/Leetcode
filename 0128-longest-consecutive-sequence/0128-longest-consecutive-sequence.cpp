class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int>mp;
        vector<int>ans;
        
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        
        for(int i=0; i<nums.size(); i++){
            vector<int>temp;
            //this step is hard
            if(mp.count(nums[i] -1) == 0){
                temp.push_back(nums[i]);
            
            
            int t = 1;
            while(mp.count(nums[i] + t)){
                temp.push_back(nums[i]+t);
                t++;
            }
            
            if(temp.size() > ans.size())
                ans = temp;
            }
            
        }
        return ans.size();
    }
};