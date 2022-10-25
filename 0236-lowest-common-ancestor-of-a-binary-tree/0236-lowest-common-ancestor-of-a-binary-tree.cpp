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
        if(!root or root == p or root == q) return root;
        //same as the lca of bst in this we dont have to check the weights
        TreeNode* leftsearch = lowestCommonAncestor(root->left,p,q);
        TreeNode* rightsearch = lowestCommonAncestor(root->right,p,q);
        
        if(leftsearch and rightsearch) return root;
        if(leftsearch) return leftsearch;
        
        return rightsearch;
    }
};