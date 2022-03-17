class Solution {
public:
    int scoreOfParentheses(string s) {
        int res = 0, l =0;
        
       
            //if(i=0; i<s.length(); i++){
        for (int i = 0; i < s.length(); ++i){
                if(s[i] == '(') l++; else l--;
                if(s[i] == ')' && s[i-1] == '(')
                    res += 1 << l;
            }
        
        return res;
    }
};