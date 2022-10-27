class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //checking for the first row and col for the zero
        bool isColzero = false;
        bool isRowzero = false;
        
        //checking for the coloumn zeroth
        for(int i=0; i<matrix.size(); i++){
            if(matrix[i][0] == 0){
                isColzero = true;
                break;
            }
        }
        //checking for the row zeroth
        for(int j=0; j<matrix[0].size(); j++){
            if(matrix[0][j] == 0){
                isRowzero = true;
                break;
            }
        }
        
        //checking for the first row and the col except filling the zero
        for(int i=1; i<matrix.size(); i++){
            for(int j=1; j<matrix[0].size(); j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        //filling the rest of the zeros
        for(int i=1; i<matrix.size(); i++){
            for(int j=1; j<matrix[0].size(); j++){
                if(matrix[i][0] == 0 or matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
        
        //chking for the zerorow and zerocol for the first row and col
        if(isColzero){
            for(int i=0; i<matrix.size(); i++)
                matrix[i][0] = 0;
        }
        
        if(isRowzero){
            for(int i=0; i<matrix[0].size(); i++)
                matrix[0][i] = 0;
        }
    }
};