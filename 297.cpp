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

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        if(!root) return res;
        queue<TreeNode*>q;
        q.push(root);
        res+=to_string(root->val);
        res+=' ';
        while(q.size()){
            auto cur=q.front();
            q.pop();
            if(cur->left){
                q.push(cur->left);
                res+=to_string(cur->left->val);
            }
            else res+="null";
            res+=' ';
            if(cur->right){
                q.push(cur->right);
                res+=to_string(cur->right->val);
            }
            else res+="null";
            res+=' ';
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return NULL;
        stringstream ss(data);
        queue<TreeNode*>q;
        string cur;
        ss>>cur;
        TreeNode* root=new TreeNode(stoi(cur));
        q.push(root);
        while(q.size()){
            auto ft=q.front();
            q.pop();
            ss>>cur;
            if(!isalpha(cur[0])){
                ft->left=new TreeNode(stoi(cur));
                q.push(ft->left);
            }
            ss>>cur;
            if(!isalpha(cur[0])){
                ft->right=new TreeNode(stoi(cur));
                q.push(ft->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
