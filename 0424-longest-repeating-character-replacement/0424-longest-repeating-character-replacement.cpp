/*
Runtime: 4 ms, faster than 98.04% of C++ online submissions for Longest Repeating Character Replacement.
Memory Usage: 7 MB, less than 53.00% of C++ online submissions for Longest Repeating Character Replacement.
*/
class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int>mp;
        int maxcnt = 0;
        int cnt = 0;
        for(auto i=0; i<s.size(); i++){
            int freq = ++mp[s[i]];
            maxcnt = max(maxcnt, freq); 
            if(cnt - maxcnt < k){
                cnt++; 
            }
            else
                mp[s[i-cnt]]--;
        }
        return cnt;
    }
};