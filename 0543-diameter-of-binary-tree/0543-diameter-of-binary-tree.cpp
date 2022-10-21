/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//basically diameter of a tree tends to the longest path leff to node
class Solution {
private:
    int diameter(TreeNode* root, int& d){
        if(root==nullptr) return 0;
        int h1 = diameter(root->left, d);
        int h2 = diameter(root->right, d);
        d = max(d, h1+h2);
        return max(h1,h2)+1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;
        int d = 0;
        diameter(root,d);
        return d;
    }
};