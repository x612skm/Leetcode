class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        
        int mainsize= m * n;
        
        if(r * c!= mainsize) return mat;
        
        vector<vector<int>>ans(r,vector<int>(c));
        
        for(int i=0; i<mainsize; i++){
            ans[i/c][i%c] = mat[i/n][i%n];
        }
        return ans;
    }
};