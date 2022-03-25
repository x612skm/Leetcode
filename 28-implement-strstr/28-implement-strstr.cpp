class Solution {
public:
    int strStr(string haystack, string needle) {
        string str;
        if(size(needle) == 0 || haystack == needle) return 0;
        if(haystack.size() < needle.size()) return -1;
        for(int i=0; i<=haystack.size()-needle.size(); i++)
        {
            str = haystack.substr(i,needle.size());
            if(str == needle)
                return i;
        }
        return -1;
    }
};