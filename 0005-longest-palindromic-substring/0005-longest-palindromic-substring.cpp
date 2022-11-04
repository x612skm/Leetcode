class Solution {
public:
    string longestPalindrome(string s) {
        
        
        int left; int right;
        
        string res = "";
        int reslen = 0;
        
        for(int i=0; i<s.size(); i++){
             left = i, right = i;
            while(left >= 0 and right < s.size() and s[left] == s[right]){
                if(right - left + 1 > reslen){
                    reslen = right - left + 1;
                    res = s.substr(left,right - left + 1);
                }
                left--;
                right++;
            }
            //for evn length
             left = i, right = i+1;
            while(left >= 0 and right < s.size() and s[left] == s[right]){
                if((right - left + 1) > reslen){
                    reslen = right - left + 1;
                    res = s.substr(left, right-left+1);
                }
                left--;
                right++;
            }
         }
        return res;
    }
};