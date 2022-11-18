class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int>mp;
        int maxcnt = 0;
        int cnt = 0;
        for(auto i=0; i<s.size(); i++){
            //mp[s[i]]++;
            maxcnt = max(maxcnt, ++mp[s[i]]);
            //ut<<maxcnt<<" ";
            if(cnt - maxcnt < k){
                cnt++; 
            }
            else
                mp[s[i-cnt]]--;
        }
        return cnt;
    }
};