class Solution {
public:
    int strStr(string haystack, string needle) {
        if(size(needle)==0 or haystack == needle ) return 0;
        if(size(haystack) < size(needle)) return -1;
        
        for(int i=0; i<= haystack.size() - needle.size(); i++){
            string str = haystack.substr(i,size(needle));
            if(str == needle)
                return i;
        }
        return -1;
    }
};