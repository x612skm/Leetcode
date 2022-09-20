class Solution {
public:
    int target;
    vector<int>temp;
    vector<vector<int>> res;
    void dfs(vector<vector<int>>& graph, int currNode = 0){
        temp.push_back(currNode);
        if(currNode == target)
            res.push_back(temp);
        else for (int node: graph[currNode]) {
            dfs(graph, node);
        }
        temp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
         target = graph.size()-1;
        dfs(graph);
        return res;
    }
};