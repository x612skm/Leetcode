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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == nullptr)
            return {};
        vector<vector<int>> ans;
        queue<TreeNode*>q;
        //ans.push_back(root);
        q.push(root);
        int level = 0;
        while(!q.empty()){
            int len = q.size();
            vector<int>temp(len);
            for(auto i=0; i<len; i++){
                TreeNode* curr = q.front();
                q.pop();
                
                //temp.push_back(curr->val);
                if(level == 0)
                    temp[i] = curr->val;
                else
                    temp[len-i-1] = curr->val;
                
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            ans.push_back(temp);
            //level = !level; //*
            level == 0? level = 1 : level = 0;
        }
        return ans;
    }
};