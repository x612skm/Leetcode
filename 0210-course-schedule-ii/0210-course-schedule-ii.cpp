class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        vector<int> indegree(numCourses,0);
        //1.
        vector<int> ans;
        //compute indegree for each node
        for(auto p:prerequisites){
            adj[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }
        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if(indegree[i] == 0)
                q.push(i);
        }
        
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            ans.push_back(curr);
            numCourses--;
            
            for(auto child : adj[curr]){
                if(--indegree[child] == 0)
                    q.push(child);
            }
        }
        if(numCourses != 0) return {};
        return ans;
    }
};