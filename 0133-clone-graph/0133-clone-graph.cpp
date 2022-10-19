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
    creating a new node will be
    Node* copy = new Node(node->val, {}); //having no neighbors
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        //using this as the bfs because we have to search for the nodes and the relations
        //at the same time
        //there is a think of the bfs
        unordered_map<Node*, Node*> mp;
        if(node == nullptr) return nullptr;
        //makign a new copy of the node
        Node* copy = new Node(node->val, {});
        //since using bfs making a queue for the storage for the curr nodes
        queue<Node*> storage;
        
        mp[node] = copy;
        storage.push(node);
        
        while(!storage.empty()){
            Node* curr = storage.front();
            storage.pop();
            
            for(Node* neigh : curr -> neighbors){
                if(mp.find(neigh) == mp.end()){
                    mp[neigh] = new Node(neigh->val, {});
                    storage.push(neigh);
                }
                //this will create the nodes for this
                //neigh stands for the curr k neighbours
                //mp[1] -> neighbors.push_back(mp[2,4]);
                mp[curr] -> neighbors.push_back(mp[neigh]);
            }
        }
        return copy;
    }
};