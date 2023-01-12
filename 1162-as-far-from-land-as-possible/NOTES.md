3 TEMPLATE 1 SOLUTION
```
//taking it from the rotting oranges code with minimum changes
//Leetcode: 1162 As Far from Land as Possible
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
if(neighbour_row < 0  or neighbour_row == rowsize or neighbour_col < 0 or neighbour_col == colsize or mat[neighbour_row][neighbour_col] != -1) {continue;}