class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat[0].size(); // column size
        for(int i=0; i<mat.size(); i++)
            mat[i].push_back(i);
        
        sort(mat.begin(), mat.end());
        vector<int>ans(k);//ans will be of k size
        for(int i=0; i<k; i++){
            ans[i] = mat[i][n];
        }
        return ans;
    }
};