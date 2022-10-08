class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mp;
        if(s.length() != t.length()) return false;
        for(int i=0; i<s.size(); i++){
            mp[s[i]]++;
            mp[t[i]]--;
        }
        
        for(auto c:mp){
            if(c.second) return false;
        }
        return true;   
    }
};