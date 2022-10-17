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
        if(root == nullptr)
            return 0;
        int h1 = height(root->left);
        int h2 = height(root->right);
        
        return max(h1,h2)+1;
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        int differnce = abs(leftHeight - rightHeight);
        
        if(differnce > 1) return false;
        if(!isBalanced(root->left)) return false;
        if(!isBalanced(root->right)) return false;
        
        return true;
    }
};