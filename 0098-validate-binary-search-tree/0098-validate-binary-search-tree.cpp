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
    vector<int> ans;
    void solve(TreeNode* root){
        if(!root) return;

        solve(root->left);
        ans.push_back(root->val);
        solve(root->right);
    }
    bool isValidBST(TreeNode* root) {
        solve(root);

        for(int i=1; i<ans.size(); i++){
            if(ans[i]<=ans[i-1]) return false;
        }
        return true;
    }
}; 
// can also implement by maintaining a range min and max if val goes beyond the limit 
// return false and at every recursion call update the limit 