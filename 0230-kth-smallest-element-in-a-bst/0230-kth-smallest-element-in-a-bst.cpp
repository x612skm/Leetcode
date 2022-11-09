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
struct comparator{
    bool operator()(int l, int r){  
       return l > r;  
    }
};
private:
    void preorder(TreeNode* root, priority_queue<int, vector<int>, greater<int>>&pq){
        //root->Leftright;
        if(root==nullptr) return;
        pq.push(root->val);
        
        preorder(root->left, pq);
        preorder(root->right, pq);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int, vector<int>, greater<int>>pq;
        preorder(root,pq);
        while(--k){
            pq.pop();
        }
        return pq.top();
    }
};