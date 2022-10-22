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
    bool compare(TreeNode* root1 , TreeNode*root2){
        if(root1 == nullptr or root2==nullptr) return root1 == root2;
        //if(root1->val == root2->val) return true;
        return root1->val == root2->val and compare(root1->left, root2->left) and compare(root1->right, root2->right);
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return compare(p,q);
    }
};