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
    void checksum(TreeNode* root, int targetSum, vector<int>&curr, vector<vector<int>>&ans){
        //checking with the base case
        if(root==NULL)
            return;
        //push the first element into
        curr.push_back(root->val);
        //checking for the leaf node
        if(root->val == targetSum and root->right == nullptr and root->left == nullptr)
            ans.push_back(curr);
            
        checksum(root->left, targetSum-root->val, curr, ans);
        checksum(root->right, targetSum-root->val, curr, ans);
        curr.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        //just like haspathsum leetcode 112
        //we have to check for the pathsum
        vector<vector<int>>ans;
        vector<int>curr;
        checksum(root, targetSum, curr, ans);
        return ans;
    }
};