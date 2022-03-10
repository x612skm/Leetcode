class Solution {
public:
    string toLowerCase(string s) {
        string ans ="";
        for(int i=0; i<s.length(); i++)
            ans += tolower(s[i]);
        
        return ans;
    }
};