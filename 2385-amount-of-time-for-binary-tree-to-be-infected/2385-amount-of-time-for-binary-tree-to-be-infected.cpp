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
    unordered_map<TreeNode*, TreeNode*> parent;
    TreeNode* initialpoint = nullptr;
    int point;
    void inorder(TreeNode* root){
        if(!root) return;
        if(root->val == point) initialpoint = root;

        if(root->left) parent[root->left] = root;
        inorder(root->left);

        if(root->right) parent[root->right] = root;
        inorder(root->right);
    }
    int bfs(TreeNode* root){
        queue<TreeNode* > q;
        q.push(root);

        unordered_map<TreeNode*, bool> visited;
        visited[root] = 1;

        int t = 0;

        while(!q.empty()){
            int n = q.size();

            while(n--){
                TreeNode* node = q.front();
                q.pop();

                //left
                if(node->left && !visited[node->left]){
                    q.push(node->left);
                    visited[node->left] = 1;
                }

                //right
                if(node->right && !visited[node->right]){
                    q.push(node->right);
                    visited[node->right] = 1;
                }

                //parent
                if(parent.count(node) && !visited[parent[node]]){
                    q.push(parent[node]);
                    visited[parent[node]] = 1;
                }
            }
            t++;
        }
        return t-1;
    }
    int amountOfTime(TreeNode* root, int start) {
        point = start;
        inorder(root);
        return bfs(initialpoint);
    }
};