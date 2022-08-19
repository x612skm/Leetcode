class Solution {
public:
    string removeDuplicates(string s) {
        int i = 0;
        int n = s.size();
        for(int j=0; j<n; j++, i++){
            s[i] = s[j];
            if(i > 0 and s[i-1] == s[i])
                i -= 2; //to remove two dupplicates
        }
        return s.substr(0,i);
        
    }
};