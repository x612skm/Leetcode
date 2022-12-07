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
private:
    bool checker(TreeNode* root, long min, long max){
        if(!root) return true;
        if(root->val <= min or root->val >= max)
            return false;
        return checker(root->left, min, root->val) and checker(root->right, root->val,max);
    }
public:
    bool isValidBST(TreeNode* root) {
        return checker(root, LONG_MIN, LONG_MAX);
        
    }
};