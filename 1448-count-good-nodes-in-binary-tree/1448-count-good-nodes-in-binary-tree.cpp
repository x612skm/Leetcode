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
    void dfs(TreeNode* root, int currmax, int& cnt){
        //int cnt=0; 
        if(!root) return;
        if(root->val >= currmax){
            cnt++;
            currmax = root->val;
        }
        dfs(root->left, currmax, cnt);
        dfs(root->right, currmax, cnt);
    }
public:
    int goodNodes(TreeNode* root) {
        int count = 0;
        dfs(root, root->val, count);
        return count;
    }
};