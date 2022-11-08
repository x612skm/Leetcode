class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
         unordered_map<int, int>mp;
        int count = 0;
        for(auto& it:tasks){
            mp[it]++;
            count = max(count, mp[it]);
        }
        int ans = (count - 1) * (n + 1);
        
        for(auto& it:mp) if(it.second == count) ans++;
        return max((int)tasks.size(), ans);
   }
};