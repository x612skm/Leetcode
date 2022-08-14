class Solution {
public:
    bool isPalindrome(string& s, int l, int r){
        while(l<r){
            if(s[l++] != s[r--])
                return false;
        }
        return true;
    }
    void par(string& s, int start, vector<vector<string>>& result, vector<string>& path){
        int n = s.size();
        if(start == n)
            result.push_back(path);
        else{
            for(int i=start; i<n; i++){
                if(isPalindrome(s,start,i)){
                    path.push_back(s.substr(start,i-start+1));
                    par(s,i+1,result,path);
                    path.pop_back();
                }
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path;
        par(s,0,result,path);
        return result;
    }
};