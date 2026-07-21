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
    priority_queue<int> pq;
    void solve(TreeNode* root, int k){
        if(!root) return;
        pq.push(root->val);
        if(pq.size() > k) pq.pop();

        solve(root->left,k);
        solve(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        solve(root,k);
        return pq.top();
    }
};