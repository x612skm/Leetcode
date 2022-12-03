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
    int diameter(TreeNode* root, int& d){
        if(!root) return 0;
        int leftheight = diameter(root->left, d);
        int rightheight = diameter(root->right, d);
        d = max(d, leftheight+rightheight);
        return max(leftheight, rightheight) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int d = 0;
        diameter(root, d);
        return d;
    }
};