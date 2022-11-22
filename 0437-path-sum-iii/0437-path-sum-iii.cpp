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
    int count(TreeNode* root, long int targetSum){
        int ans = 0;
        if(!root) return 0;
        return (root->val == targetSum ? 1 : 0) + count(root->left, targetSum - root->val) + count(root->right, targetSum-root->val);
        
        //return ans;
        
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        return count(root, targetSum) + pathSum(root->left,targetSum) + pathSum(root->right, targetSum);
    }
};