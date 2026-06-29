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
    int maxi = INT_MIN;
    int solve(TreeNode* root){
        if(root == NULL) return 0;

        int left = 1+solve(root->left);
        int right = 1+solve(root->right);
        maxi = max(abs(left-right), maxi);
        return max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        int maxdiff = solve(root);
        if(maxi>1) return false;
        else return true;
    }
};