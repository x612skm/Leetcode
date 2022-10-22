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
public:
    TreeNode* construction(vector<int>& nums, int left, int right){
        if(left > right) return NULL;
        int idx = (left+right) >> 1;
        TreeNode* root = new TreeNode(nums[idx]);
        root->left = construction(nums, left, idx-1);
        root->right = construction(nums, idx+1, right);
        
        return root;
        
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return construction(nums,0,nums.size()-1);
    }
};