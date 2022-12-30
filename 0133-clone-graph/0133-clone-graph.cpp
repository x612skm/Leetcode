/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node)
            return nullptr;
        return dfs(node);
    }
private:
    unordered_map<Node*, Node*> mp;
    Node* dfs(Node* node){
        if(mp.find(node) != mp.end())
           return mp[node];
        
        //create the first node
        Node* neew = new Node(node->val);
        mp[node] = neew;
        
        for(auto neigh : node->neighbors){
            neew->neighbors.push_back(dfs(neigh));
        }
        return neew;
    }
};