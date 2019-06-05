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
        if(!root) return "";
        string res;
        stack<TreeNode*>s;
        s.push(root);
        while(s.size()){
            auto cur=s.top();
            res+=to_string(cur->val)+' ';
            s.pop();
            if(cur->left) s.push(cur->left);
            if(cur->right) s.push(cur->right);
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        int x;
        TreeNode* head=NULL;
        while(ss>>x) head=insert(head,x);
        return head;
    }
    
    TreeNode* insert(TreeNode* T,int x){
        if(!T) T=new TreeNode(x);
        else{
            if(x<T->val) T->left=insert(T->left,x);
            else T->right=insert(T->right,x);
        }
        return T;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
