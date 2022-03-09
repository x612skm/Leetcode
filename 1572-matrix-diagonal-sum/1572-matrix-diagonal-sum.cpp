class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int rows = mat.size();
        int sum = 0;
        for(int i=0; i<rows; i++){
            sum += mat[i][i];
            sum += mat[rows-i-1][i];
        }
        
        if(rows % 2)
            sum -= mat[rows/2][rows/2];
        
        return sum;
    }
};