class Solution {
private:
    void dfs(vector<vector<int>>& image,int val, int sr, int sc, int color){
        if(sr<0 or sc < 0 or sr >= image.size() or sc >= image[0].size() or image[sr][sc] != val or image[sr][sc] == color)
            return;
        image[sr][sc] = color;
        dfs(image, val,sr-1, sc, color);
        dfs(image, val,sr+1, sc, color);
        dfs(image, val,sr, sc-1, color);
        dfs(image, val,sr, sc+1, color);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int val = image[sr][sc];
        dfs(image, val, sr, sc, color);
        return image;
    }
};