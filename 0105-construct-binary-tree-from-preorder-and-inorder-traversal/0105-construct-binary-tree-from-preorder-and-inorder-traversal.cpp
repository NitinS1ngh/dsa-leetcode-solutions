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
    unordered_map<int,int> mp;
    TreeNode* solve(vector<int>& preorder, int start, int end, int& idx){
        if(start>end) return nullptr;

        int rootval = preorder[idx++];
        int mid = mp[rootval];

        TreeNode* root = new TreeNode(rootval);
        root->left = solve(preorder,start,mid-1,idx);
        root->right = solve(preorder,mid+1,end,idx);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();

        for(int i=0; i<n; i++){
            mp[inorder[i]] = i;
        }

        int idx = 0;
        return solve(preorder,0,n-1,idx);
    }
};