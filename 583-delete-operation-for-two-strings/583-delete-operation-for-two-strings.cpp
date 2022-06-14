class Solution {
int t[1001][1001];
public:
    
    int lcs(string& word1, string& word2, int m, int n){
         m = word1.size();
         n= word2.size();
        int t[m+1][n+1];
        
        for(int i=0; i<m+1; i++)
        {
            for(int j=0; j<n+1; j++)
            {
                if(i==0 or j == 0)
                    t[i][j] = 0 ;
            }
        }
        
        for(int i=1; i<m+1; i++)
        {
            for(int j=1; j<n+1; j++)
            {
                if(word1[i-1] == word2[j-1])
                    t[i][j] = 1 + t[i-1][j-1];
                else
                    //t[i][j] = max(t[i][j-1], t[i-1][j]);
                    t[i][j] = max(t[i][j-1], t[i-1][j]);
            }
        }
        return t[m][n];
    }
    int minDistance(string word1, string word2) {
        int m =0 ;
        int n = 0;
        memset(t,-1,sizeof(t));
        
        int ins = word1.length() - lcs(word1, word2, m, n);
        int del = word2.length() - lcs(word1, word2, m, n);
        
        int res = abs(ins + del);
        
        return res;
        
        
    }
};