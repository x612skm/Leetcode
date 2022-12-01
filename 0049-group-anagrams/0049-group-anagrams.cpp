class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>mp;
        for(auto& s : strs){
            string t =s;
            sort(t.begin(), t.end());
            
            mp[t].push_back(s);//all the same values will be associated with the key
        }
        vector<vector<string>>ans;
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};