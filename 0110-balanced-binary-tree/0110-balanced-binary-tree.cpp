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
    int height(TreeNode* root){
        return !root ? 0 : max(height(root->left), height(root->right)) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        int leftheight = height(root->left);
        int rightheight = height(root->right);
        int diff = abs(leftheight - rightheight);
        
        if(diff > 1) return false;
        if(!isBalanced(root->left)) return false;
        if(!isBalanced(root->right)) return false;
        
        return true;
    }
};