class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        cout<<(s+s).find(s, 1);
        return (s+s).find(s, 1) < s.size();
        
    }
};