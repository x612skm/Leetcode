class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        //taking the r as the vector in vector for the ans
        vector<vector<int>>r(numRows);
        //traversing for the numvers till the number
        for(int i=0; i<numRows; i++){
            //resize all the ith elements to the next i+1
            r[i].resize(i+1);
            //first and second element
            r[i][0] = r[i][i] = 1;
            
            //traverse for the rest of the rows
            for(int j=1; j<i; j++){
                //formula for pascal triangle
                r[i][j] = r[i-1][j-1] + r[i-1][j]; 
            }
        }
        return r;
    }
};