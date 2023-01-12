//taking it from the rotting oranges code with minimum changes
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int rowsize = grid.size();
        int colsize = grid[0].size();
        
        int water = 0; int land = 0; int dist = 0;
        int answer = 0;
        queue<pair<int, int>> visited;
        for(int i=0; i<rowsize; i++){
            for(int j=0; j<colsize; j++){
                if(grid[i][j] == 0) water++;
                if(grid[i][j] == 1) visited.emplace(i,j);
            }
        }
        
        if(water == 0 or visited.empty()) return -1;
        
        //applying bfs to the whole for the 4D direction
        
        vector<int>cordinates = {0,1,0,-1,0};
        
        while(!visited.empty()){
            int size = visited.size();
            dist++;
            while(size--){
                auto[row, col] = visited.front();
                visited.pop();
                
                for(int i=0; i<4; i++){
                    int neigh_row = row + cordinates[i];
                    int neigh_col = col + cordinates[i+1];
                    
                    if(neigh_row < 0 or neigh_row == rowsize or neigh_col < 0 or neigh_col == colsize or grid[neigh_row][neigh_col] != 0)
                        continue;
                    
                    answer = dist;
                    grid[neigh_row][neigh_col] = 1;
                    visited.emplace(neigh_row, neigh_col);
                }
            }
        }
        return answer;
    }
};