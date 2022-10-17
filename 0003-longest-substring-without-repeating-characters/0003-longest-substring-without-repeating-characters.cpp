class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //we are using here unordered_map for the hashing complexity of O(1);
        unordered_map<char, int>mp;
        int maxLen = 0; int start = -1;
        for(int i=0; i<s.size(); i++){
            if(mp.count(s[i]) != 0){
                start = max(start, mp[s[i]]);
            }
            mp[s[i]] = i;
            maxLen = max(maxLen, i-start);//the where the new started again
        }
        return maxLen;
    }
};