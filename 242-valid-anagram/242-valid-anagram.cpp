class Solution {
public:
    bool isAnagram(string s, string t) {
//         sort(s.begin(), s.end());
//         sort(t.begin(), t.end());        
//         return s==t;
        /*method 2*/
        
        if(s.length() != t.length()) return false;
        unordered_map<char, int> mp;
        for(int i=0; i<s.length(); i++){
            mp[s[i]]++;
            mp[t[i]]--;
        }
        
        for(auto c : mp)
            if(c.second) return false;
        return true;
    }
};