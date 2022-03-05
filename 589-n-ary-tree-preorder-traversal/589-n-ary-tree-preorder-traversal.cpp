/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void helper(Node* root, vector<int>& res){
        if(!root) return;
        res.push_back(root->val);
        for(auto child : root->children){
            helper(child, res);
        }
    }
    vector<int> preorder(Node* root) {
        auto res = vector<int>();
        
        helper(root, res);
        return res;
    }
};