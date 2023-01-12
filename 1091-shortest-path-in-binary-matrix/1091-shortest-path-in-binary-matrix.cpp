class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        //writing rotting oranges code with little modification
        //we have to look for 8 directions
        int rowsize = grid.size();
        int colsize = grid[0].size();//there is no need to find it as the constraints 
        //remained the same for the row and cols 
        
        queue<pair<int,int>> visited;
        if(grid[0][0] == 1 or grid[rowsize-1][colsize-1] == 1) return -1;
        int pathcount = 1;
        
        vector<int> xcordinates = {-1,-1,-1,0,0,1,1,1};
        vector<int> ycordinates = {-1,0,1,-1,1,-1,0,1};
        
        //if(grid[0][0] == 0) return -1;
        
        visited.emplace(0,0);
        
        grid[0][0] = 1; //mark it as visited;
        
        
        //calling bfs
        while(!visited.empty()){
            int size = visited.size();
            while(size--){
                auto[row, col] = visited.front();
                visited.pop();
                //when it comes to the last box of the grid
                if(row == rowsize-1 and col == colsize-1) return pathcount;
                
                for(int i=0; i<8; i++){
                    int neigh_row = row + xcordinates[i];
                    int neigh_col = col + ycordinates[i];
                    //checking for the out of bound conditons
                    if(neigh_row >=0 and neigh_col >=0 and neigh_row < rowsize and neigh_col < colsize and grid[neigh_row][neigh_col] ==0){
                    grid[neigh_row][neigh_col] = 1;
                    visited.emplace(neigh_row, neigh_col);
                    }
                }
            }
            pathcount++;
        }
        return -1;
    }
};