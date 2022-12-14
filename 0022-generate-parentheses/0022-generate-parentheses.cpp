class Solution {
private:
    void generate(vector<string>& ans, string p, int n, int m){
        //using backtracking template
        if(n==0 and m==0){
            ans.push_back(p);
            return;
        }
        
        if(n>0) generate(ans, p + '(', n-1, m+1);
        if(m>0) generate(ans, p + ')', n, m-1);
    }
public:
    vector<string> generateParenthesis(int n) {
        //making the return type
        vector<string> ans;
        string p = "";
        generate(ans, p, n, 0);
        return ans;
    }
};