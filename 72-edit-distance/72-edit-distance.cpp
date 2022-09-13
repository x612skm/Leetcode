class Solution {
public:
    int editDistanceDP(string s1, string s2){
    int m = s1.size();
    int n = s2.size();
    //base case
    //if(m == 0 or n == 0) return max(m,n);
    //if(s1 == s2) return 0;
    
    int **output = new int*[m+1];
    for(int i=0; i<=m; i++)
        output[i] = new int[n+1];
    
    //int ans;
    //for the row constant col changes
    for(int i=0; i<=n; i++)
        output[0][i] = i;
    //for the col constant row changes
    for(int j=1; j<=m; j++)
        output[j][0] = j;
    
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(s1[m-i] == s2[n-j])
                output[i][j] = output[i-1][j-1];
            else{
			int x = output[i-1][j];
            int y = output[i][j-1];
            int z = output[i-1][j-1];
            
            output[i][j] = min(x,min(y,z)) + 1;
            //output[i][j] = ans;
            }
        }
    }
    return output[m][n];
}
    int minDistance(string word1, string word2) {
        int ans =  editDistanceDP(word1,word2);
        return ans;
    }
};