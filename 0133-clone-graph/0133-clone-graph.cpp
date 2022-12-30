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
        mp[node] = neew;//mapping the first node
        
        //traversing to the every node and calling dfs for the neightbours
        for(auto neigh : node->neighbors){
            //it will create a new node everytime and map it with the node of graph
            neew->neighbors.push_back(dfs(neigh));
        }
        return neew;
    }
};