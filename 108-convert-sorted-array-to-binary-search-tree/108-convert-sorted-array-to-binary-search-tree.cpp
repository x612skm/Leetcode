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
    
    TreeNode* make(vector<int>& nums, int low, int high){
        
        if(low<=high)
        {
            int mid = low + (high-low)/2;
            //assigning the root
            TreeNode* root = new TreeNode(nums[mid]);
            
            root -> left = make(nums, low, mid-1);
            root -> right = make(nums, mid+1, high);
            return root;
            
        }
        return NULL;
    }
//public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return make(nums,0,nums.size()-1);
    }
};