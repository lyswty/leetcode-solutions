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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        if(key<root->val) root->left=deleteNode(root->left,key);
        else if(key>root->val) root->right=deleteNode(root->right,key);
        else if(!root->left&&!root->right){
            delete root;
            return NULL;
        }
        else if(root->left){
            auto ptr=root->left;
            while(ptr->right) ptr=ptr->right;
            root->val=ptr->val;
            root->left=deleteNode(root->left,ptr->val);
        }
        else{
            auto ptr=root->right;
            while(ptr->left) ptr=ptr->left;
            root->val=ptr->val;
            root->right=deleteNode(root->right,ptr->val);
        }
        return root;
    }
};
