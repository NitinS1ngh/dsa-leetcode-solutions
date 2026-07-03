class Solution {
public:
    bool found = false; // global flag to stop recursion once node found

    void solve(TreeNode* root, TreeNode* node, vector<TreeNode*>& path) {
        if (root == nullptr || found) return;  // stop if null or already found

        path.push_back(root);

        if (root == node) { // target found
            found = true;
            return;
        }

        solve(root->left, node, path);
        solve(root->right, node, path);

        if (!found) path.pop_back(); // backtrack only if not found
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathp;
        vector<TreeNode*> pathq;

        found = false;
        solve(root, p, pathp);   // get path for p

        found = false;
        solve(root, q, pathq);   // get path for q

        int i = 0;
        while (i < pathp.size() && i < pathq.size() && pathp[i] == pathq[i])
            i++;

        return pathp[i - 1];
    }
};
