class Solution {
public:
    char findTheDifference(string s, string t) {
        char c = 0;
        
        for(auto cs : s) c ^= cs;
        for(auto ct : t) c ^= ct;
        
        return c;
    }
};