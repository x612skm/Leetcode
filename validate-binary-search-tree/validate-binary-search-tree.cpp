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
    bool check(TreeNode* root, TreeNode* min, TreeNode* max){
        if(!root) return true;
        if((min == NULL or root->val > min -> val) and (max == NULL or root->val < max->val)){
            return check(root->left, min, root) and check(root->right, root, max);
        }
        return false;
    }
    bool isValidBST(TreeNode* root) {
        return check(root,NULL, NULL);
    }
};