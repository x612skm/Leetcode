/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr or p == root or q==root) return root;
        TreeNode* lefts = lowestCommonAncestor(root->left, p ,q);
        TreeNode* rights = lowestCommonAncestor(root->right, p, q);
        
        if(lefts and rights) return root;
        if(lefts) return lefts;
        else return rights;
    }
};