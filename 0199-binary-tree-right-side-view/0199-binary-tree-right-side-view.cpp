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
    void dfs(vector<int>&ans, TreeNode* root, int level){
        if(!root) return;
        if(level > ans.size())
            ans.push_back(root->val);
        
        dfs(ans, root->right, level+1);
        dfs(ans, root->left, level+1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        dfs(ans, root, 1);
        return ans;
    }
};