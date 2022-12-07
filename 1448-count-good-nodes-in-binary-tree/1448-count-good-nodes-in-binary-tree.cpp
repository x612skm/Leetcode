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
    void count(TreeNode* root, int& cnt, int currmax){
        if(!root) return;
        if(root->val >= currmax){
            cnt++;
            currmax = root->val;
        }
        count(root->left, cnt, currmax);
        count(root->right, cnt, currmax);
    }
public:
    int goodNodes(TreeNode* root) {
        int cnt = 0;
        count(root, cnt, root->val);
        return cnt;
    }
};