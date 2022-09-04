class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<int,int> mp;
        for(int i=0; i<s.size(); i++){
            if(mp.count(s[i]) == 0)
                mp[s[i]] = 2;
            else
                mp[s[i]]++;
        }
        
        for(int i=0; i<s.size(); i++){
            if(mp[s.at(i)] == 2)
                return i;
        }
        return -1;
    }
};