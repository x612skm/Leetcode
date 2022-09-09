class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        //string therefore there will be a string output
        vector<vector<string>> res;
        vector<string>nqueen(n,string(n,'.'));
        solve(res,nqueen,0,n);
        return res;
    }
    
private:
    void solve(vector<vector<string>> &res,vector<string> &nqueen, int row, int& n){
        //we have to check the given 4 arguments
        if(row == n){
            res.push_back(nqueen); 
            return;
        }
        
        for(int col = 0; col !=n; col++){
            if(isvalid(nqueen, col, row, n)){
                nqueen[row][col] = 'Q';
                solve(res,nqueen,row+1,n);
                nqueen[row][col] = '.';
            }
        }
    }
    
    bool isvalid(vector<string>& nqueen,int col, int row, int&n){
        //we will check here three cases for the follwing queen that
        //kill or not kill queen
        //checking the same cols
        for(int i=0; i!=row; i++)
            if(nqueen[i][col] == 'Q')
                return false;
        
        //checking the left diagonal
        for(int i = row-1, j= col-1; i>= 0 and j>=0 ; --i, --j){
            if(nqueen[i][j] == 'Q')
                return false;
        }
        
        //checking for the upper right diagonal
        for(int i = row-1, j= col+1; i>= 0 and j<n ; --i, j++){
            if(nqueen[i][j] == 'Q')
                return false;
        }
        return true;
    }
};