class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //if there is a cycle then it is false
        //khan's algorithm for finding the cycle if there is cycle is present 
        //that is if the numCourses becomes 0 then it is true
        vector<int> adj[numCourses];
        vector<int> indegree(numCourses,0);
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
            int s = q.size();
            while(s--){
            int curr = q.front();
            q.pop();
            numCourses--;
            
            for(auto child : adj[curr]){
                if(--indegree[child] == 0)
                    q.push(child);
            }
        }
        }
        return numCourses==0;
        
    }
};