else
mat[row][col] = -1; //this gives as not visited;
}
}
while(!visited.empty()){
int size = visited.size();
while(size--){
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
}
return mat;
}
};
```