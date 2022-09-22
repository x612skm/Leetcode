class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        //indegree not
        //only outdegree nodes are the answers
        vector<int>result, seen(n);
        
        for(auto e : edges){
            seen[e[1]] = 1;
        }
        for(int i=0; i<n; i++){
            if(seen[i] == 0)
                result.push_back(i);
        }
        return result;
        seen.clear();
        result.clear();
    }
};