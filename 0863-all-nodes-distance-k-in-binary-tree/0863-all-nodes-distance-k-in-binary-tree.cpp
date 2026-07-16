/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;
    vector<int> ans;
    void inorder(TreeNode* root){
        if(!root) return;

        if(root->left) parent[root->left] = root;
        inorder(root->left);

        if(root->right) parent[root->right] = root;
        inorder(root->right);
    }
    void bfs(TreeNode* target, int k){
        queue<TreeNode*> q;
        q.push(target);
        unordered_map<TreeNode*, bool> visited;
        visited[target] = 1;

        while(!q.empty()){
            int n = q.size();

            if(k==0) break;

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
                if (parent.count(node) && !visited[parent[node]]) {
                    visited[parent[node]] = true;
                    q.push(parent[node]);
                }
            }
            k--;
        }
        while (!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        inorder(root);
        bfs(target, k);
        return ans;
    }
};