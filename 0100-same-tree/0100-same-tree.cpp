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
    bool compare(TreeNode* left_side, TreeNode* right_side){
        if(left_side == nullptr or right_side == nullptr) return left_side == right_side;
        return left_side->val == right_side->val and compare(left_side->left, right_side->left) and compare(left_side->right, right_side->right);
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return compare(p,q);
    }
};