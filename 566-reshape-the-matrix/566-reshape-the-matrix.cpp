class Solution{
public:
vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int flatten[r*c];
        int m=mat.size();
        int n=mat[0].size();
        if(r==m && c==n || r*c != mat.size()*mat[0].size()){
            return mat;
        }
        vector<vector<int>> res;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                flatten[mat[0].size()*i+j]=mat[i][j];
            }
        }
        int k=0;
        for(int i=0;i<r;i++){
            vector<int> temp;
            for(int j=0;j<c;j++){
                temp.push_back(flatten[k++]);
            }
            res.push_back(temp);
            
        }
        return res;
}
};