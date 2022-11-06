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
    TreeNode* builder(vector<int>&preorder, vector<int>&inorder, int& index, int s, int e){
        if(s>e) return nullptr;
        //index = 0;
        
        TreeNode* root = new TreeNode(preorder[index]);
        int split = 0;
        //splitting fn for
        for(int i=0; i<inorder.size(); i++){
            if(preorder[index] == inorder[i]){
                split = i;
                    break;
            }
            //index++;
        }
        index++;
        
        root->left = builder(preorder, inorder, index, s, split-1);
        root->right = builder(preorder, inorder, index, split+1, e);
        
        return root;
        
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index=0;
        return builder(preorder, inorder,  index, 0, inorder.size()-1);
    }
};