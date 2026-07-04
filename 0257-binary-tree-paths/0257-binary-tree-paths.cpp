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
    vector<string> ans;
    void solve(TreeNode* root, string path){
        if(!root) return;
        path += to_string(root->val);

        if(root->left==NULL && root->right==NULL){
            ans.push_back(path);
            return;
        }
        
        path += "->";

        solve(root->left,path);
        solve(root->right,path);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return ans;
        solve(root,"");
        return ans;
    }
};