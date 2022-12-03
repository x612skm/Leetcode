class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int>mp;
        int maxlen = 0; int start = -1;
        
        for(auto i=0; i<s.size(); i++){
            if(mp.count(s[i])!=0)
                start = max(start, mp[s[i]]);
            mp[s[i]] = i;
            maxlen = max(maxlen, i-start);
        }
        return maxlen;
    }
};