/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<TreeNode*> nodes;

    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);
        nodes.push_back(root);
        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        inorder(root);

        int first = -1, second = -1;

        for (int i = 0; i < nodes.size() - 1; i++) {
            if (nodes[i]->val > nodes[i + 1]->val) {
                if (first == -1)
                    first = i;
                second = i + 1;
            }
        }

        swap(nodes[first]->val, nodes[second]->val);
    }
};