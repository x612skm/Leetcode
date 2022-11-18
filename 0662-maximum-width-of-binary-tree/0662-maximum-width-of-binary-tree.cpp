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
    int widthOfBinaryTree(TreeNode* root) {
        
        if(!root) return 0;
        queue<pair<TreeNode*, int>>q;
        
        q.push({root,1});
        
        int ans = 0;
        
        while(!q.empty()){
            int size = q.size();
            
            int start  =q.front().second;
            int end = q.back().second;
            ans = max(end- start + 1, ans);
            
            while(size-- > 0){
                auto node = q.front().first;
                auto idx =  q.front().second- start;//to avoid the overflow considering it a skew tree
                //auto [node, idx] = q.front();
                q.pop();
                
                if(node -> left)
                    q.push({node->left, (long long)2 * idx});
                if(node -> right)
                    q.push({node->right, (long long)2 * idx+ 1});
            }
        }
        return ans;
    }
};