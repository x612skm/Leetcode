class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n==0)
            return "";
        //make it a true
        bool dp[n][n];
        
        //initlise all the as the false
        memset(dp,0,sizeof(dp));
        
        for(int i=0; i<n; i++)
            dp[i][i] = true;
        
        string ans = "";
        ans += s[0]; //start has the palindrome
        
        for(int i = n - 1; i >= 0; i--){
            for (int j = i + 1; j < n; j++){
                if(s[i] == s[j]){
                    //if it a 2 character or its substring problem
                    if (j - i == 1 || dp[i + 1][j - 1]){
                        dp[i][j] = true;
                        if(ans.size() < j-i+1)
                            ans = s.substr(i,j-i+1);
                    }
                }
            }
        }
        return ans;
    }
};