class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rowsize = matrix.size();
        int colsize = matrix[0].size();
        
        vector<int>rowmarker(rowsize,1);
        vector<int>colmarker(colsize,1);
        
        for(int i=0; i<rowsize; i++){
            for(int j=0; j<colsize; j++){
                if(matrix[i][j] == 0){
                    rowmarker[i] = 0;
                    colmarker[j] = 0;
                }
            }
        }
        
        for(int i=0; i<rowsize; i++){
            for(int j=0; j<colsize; ++j){
                if(rowmarker[i] == 0 or colmarker[j] == 0)
                    matrix[i][j] = 0;
            }
        }
    }
};