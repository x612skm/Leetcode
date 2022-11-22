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
    int ans = 0;
private:
    void count(TreeNode* root, long int targetSum){
        if(!root) return;
        if(root->val == targetSum)
            ans++;
        
        count(root->left, targetSum - root->val);
        count(root->right, targetSum- root->val);
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        //int ans;
        if(root)
        {
            count(root, targetSum);
            pathSum(root->left, targetSum);
            pathSum(root->right, targetSum);
        }
        return ans;
    }
};