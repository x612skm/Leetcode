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
        if(!root) return 0;
        int leftheight = height(root->left);
        int rightheight = height(root->right);
        
        return max(leftheight, rightheight) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        
        int dif = abs(height(root->left) - height(root->right));
        
        if(dif > 1) return false;
        if(!isBalanced(root->left)) return false;
        if(!isBalanced(root->right)) return false;
        
        return true;
    }
};