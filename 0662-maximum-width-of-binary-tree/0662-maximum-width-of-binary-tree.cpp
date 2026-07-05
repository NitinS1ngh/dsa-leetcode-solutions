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
        long long ans = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root,0});

        while(!q.empty()){
            int n = q.size();
            long long minIndex = q.front().second;
            long long first, last;

            for(int i=0; i<n; i++){
                TreeNode* node = q.front().first;
                long long idx = q.front().second - minIndex;
                q.pop();

                if(i==0) first = idx;
                if(i==n-1) last = idx;

                if(node->left) q.push({node->left, 2*idx + 1});
                if(node->right) q.push({node->right, 2*idx + 2});
            }

            ans = max(ans, last-first+1);
        }

        return ans;
    }
};