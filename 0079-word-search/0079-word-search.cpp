class Solution {
private:
    //we are doing dfs backtrack
    bool dfs(vector<vector<char>>& board, string word, int index, int i, int j, int m, int n){
        //taking the base case of the graph bfs
        //classical dfs approach 
        if(i<0 or j<0 or i>=m or j>=n or board[i][j] != word[index])
            return false;
        
        //classical backtracking base case
        if(index == word.size()-1)
            return true;
        board[i][j] = '#'; //jo visit hogaya hai usko mark kardo warna phir chala jayega
        //we will check all the possible position incrementing the index in the further calls
            if(dfs(board, word, index+1, i-1, j, m, n) or
            dfs(board, word, index+1, i+1, j, m, n) or
            dfs(board, word, index+1, i, j-1, m, n) or
            dfs(board, word, index+1, i, j+1, m, n) )
                return true;
        
        board[i][j] = word[index];
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(board[i][j] == word[0]){
                    if(dfs(board, word, 0, i, j, m, n))
                        return true;
                }
            }
        }
        return false;
    }
};