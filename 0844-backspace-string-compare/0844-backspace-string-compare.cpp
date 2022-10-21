class Solution {
private:
    string compare(string s){
        int count = 0;
        string ans = "";
        for(int i=s.size()-1; i>=0; --i){
            if(!isalnum(s[i]))
                count++;
            else{
                if(count == 0){
                    ans += s[i];
                    continue;
                }
                count--;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
public:
    bool backspaceCompare(string s, string t) {
        if(compare(s) == compare(t))
            return true;
        return false;
    }
};