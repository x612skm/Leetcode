class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int>mp;
        int maxcnt = 0;
        int cnt = 0;
        for(auto i=0; i<s.size(); i++){
            int freq = ++mp[s[i]];
            maxcnt = max(maxcnt, freq);
            
            if(cnt - maxcnt < k) cnt++;// 0-1=> 1 // 1-1 // 2-2 // 3-2 // <k
            else mp[s[i-cnt]]--;
        }
        return cnt;
    }
};