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
class Solution {
public:
    //taking this from same tree
    bool compare(TreeNode* root1 , TreeNode*root2){
        if(root1 == nullptr or root2==nullptr) return root1 == root2;
        //if(root1->val == root2->val) return true;
        return root1->val == root2->val and compare(root1->left, root2->left) and compare(root1->right, root2->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr) return false;
        if(compare(root,subRoot)) return true;
        //just a little change we check either of the side of the tree for subtree
        return isSubtree(root->left, subRoot) or isSubtree(root->right, subRoot);
    }
};