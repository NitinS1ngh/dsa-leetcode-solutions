/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void serializehelper(TreeNode* root, string& s){
        if(!root){
            s += "N,";
            return;
        }

        s += to_string(root->val) + ",";
        serializehelper(root->left,s);
        serializehelper(root->right,s);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        serializehelper(root,s);
        return s;
    }

    TreeNode* deserializehelper(vector<string>& node, int& idx){
        if(node[idx] == "N"){
            idx++;
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(node[idx++]));

        root->left = deserializehelper(node,idx);
        root->right = deserializehelper(node,idx);

        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> node;
        string temp;

        for(char c: data){
            if(c == ','){
                node.push_back(temp);
                temp.clear();
            }else{
                temp += c;
            }
        }

        int idx = 0;
        return deserializehelper(node,idx);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));