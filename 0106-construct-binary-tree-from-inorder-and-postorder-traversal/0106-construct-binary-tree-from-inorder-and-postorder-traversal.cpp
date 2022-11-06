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
    TreeNode* builder(vector<int>& inorder, vector<int>&postorder, int& index, int s, int e){
        if(s>e or index < 0) return nullptr;
        
        TreeNode* root = new TreeNode(postorder[index]);
        
        int split = 0;
        for(int i=0; i<inorder.size(); i++){
            if(postorder[index] == inorder[i]){
                split = i;
                break;
            }
        }
        index--;
        
        root->right = builder(inorder, postorder, index,split+1,e);
        root->left = builder(inorder, postorder, index, s, split-1);
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int index = postorder.size()-1;
        return builder(inorder, postorder, index, 0, inorder.size()-1);
    }
};