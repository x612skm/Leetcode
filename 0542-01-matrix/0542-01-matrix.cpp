class Solution {
public:
    //emplace fn : The container is extended by inserting a new element at position. This new element is constructed in place using args as the arguments for its construction.

    vector<int> cordinates = {0,1,0,-1,0};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rowsize = mat.size();
        int colsize = mat[0].size();
        
        queue<pair<int,int>> visited;
        
        for(int row = 0; row < rowsize; ++row){
            for(int col = 0; col < colsize; ++col){
                if(mat[row][col] == 0)
                    visited.emplace(row,col);
                else
                    mat[row][col] = -1; //this gives as not visited;
            }
        }
        
        while(!visited.empty()){
            auto[row,col] = visited.front();//taking out the pairs
            visited.pop();
            for(int i=0; i<4; i++){
                //checking with the cordinates
                int neighbour_row = row + cordinates[i];
                int neighbour_col = col + cordinates[i+1];
                //checking with all the base cases
                if(neighbour_row < 0  or neighbour_row == rowsize or neighbour_col < 0 or neighbour_col == colsize or mat[neighbour_row][neighbour_col] != -1) {continue;}
                
                mat[neighbour_row][neighbour_col] = mat[row][col] + 1;
                visited.emplace(neighbour_row, neighbour_col); 
            }
        }
        return mat;
    }
};