class Solution {
public:
    vector<vector<int>> dp;
    vector<vector<string>> result;
    vector<string>storage;
    
    bool traverse(string& s,int left, int right){
        if(dp[left][right] >= 0)
            return dp[left][right];
        if(left == right)
            return dp[left][right] = 1;
        if(right-left == 1)
            return dp[left][right] = s[left] == s[right];
        
        return dp[left][right] = s[left] == s[right] and traverse(s, left+1, right-1);
        
    }
    void build(string&s, int pos){
        if(pos == s.size()){
            result.push_back(storage);
            return;
        }
        for(int curr = pos; curr < s.size(); curr++){
            if(dp[pos][curr]){
                storage.push_back(s.substr(pos,curr-pos+1));
                build(s,curr+1);
                storage.pop_back();
            }  
        }
    }
    vector<vector<string>> partition(string s) {
        dp.resize(s.size(), vector<int>(s.size(),-1));
        for(int len = 1; len <= s.size(); len++){
            for(int i=0; i <= s.size()-len; i++){
                traverse(s,i,i+len-1);
            }
        }
        build(s,0);
        return result;
    }
};