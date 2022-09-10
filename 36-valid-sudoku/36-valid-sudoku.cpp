class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //we make vector and set into the vector
        vector<set<int>> col(9);
        vector<set<int>> row(9);
        vector<set<int>> boxindex(9);
        
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] == '.')
                    continue;
                //cheking the index if inside it
                //storing the index which is not "."
                int curr = board[i][j] - '0'; //changing this into int
                if(col[j].count(curr) or row[i].count(curr) or boxindex[(i/3)*3 + (j/3)].count(curr))
                    return false;
                
                row[i].insert(curr);
                col[j].insert(curr);
                boxindex[(i/3)*3 + (j/3)].insert(curr);
            }
        }
        return true;
    }
};