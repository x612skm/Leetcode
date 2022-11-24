/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    unordered_map<TreeNode*, int>mp;
private:
    int findx(TreeNode* root, TreeNode* target){
        if(!root) return -1;
        if(root==target){
            mp[root] = 0;
            return 0;
        }
        int left = findx(root->left, target);
        if(left >= 0){
            mp[root] = left + 1;
            return left+1;
        }
        
        int right = findx(root->right, target);
        if(right >=0){
            mp[root] = right + 1;
            return right+1;
        }
        return -1;
    }
private:
    void dfs(TreeNode* root, TreeNode* target, int k, int length, vector<int>& ans){
        if(root == nullptr) return;
        if(mp.count(root))
            length = mp[root];
        
        if(length == k)
            ans.push_back(root->val);
        
        dfs(root->left, target, k, length+1, ans);
        dfs(root->right, target, k, length+1, ans);
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;
        findx(root, target);
        dfs(root, target, k,mp[root], ans);
        return ans;
    }
};