class Solution {
public:
    vector<int> findMinHeightTrees(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        vector<int> indegree(numCourses,0);
        vector<int>ans;
        //compute indegree for each node
        for(auto p:prerequisites){
            adj[p[1]].push_back(p[0]);
            adj[p[0]].push_back(p[1]);
            indegree[p[0]]++;
            indegree[p[1]]++;
        }
        //make a bfs call
        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if(indegree[i] == 1){
                q.push(i);
                indegree[i]--;
            }
        }
        
        while(!q.empty()){
            ans.clear();
            int s = q.size();
            while(s--){
                int curr = q.front();
                q.pop();
                ans.push_back(curr);
                numCourses--;

                for(auto child : adj[curr]){
                    if(--indegree[child] == 1)
                        q.push(child);
                }
            }
        }
        if(numCourses==1)
            ans.push_back(0);
        
        return ans;
    }
};