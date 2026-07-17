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
    unordered_map<int, int> mp;
    TreeNode* solve(vector<int>& postorder, int start, int end, int& idx){
        if(start > end) return NULL;

        int rootval = postorder[idx--];
        int mid = mp[rootval];
        
        TreeNode* root = new TreeNode(rootval);
        root->right = solve(postorder,mid+1,end,idx);
        root->left = solve(postorder,start,mid-1,idx);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        for(int i=0; i<n; i++){
            mp[inorder[i]] = i;
        }
        int idx = n-1;
        return solve(postorder,0,n-1,idx);
    }
};