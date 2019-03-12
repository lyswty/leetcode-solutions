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
    void flatten(TreeNode* root) {
        if(!root) return;
        swap(root->left,root->right);
        flatten(root->right);
        TreeNode* ptr;
        for(ptr=root;ptr->right;ptr=ptr->right);
        swap(ptr->right,root->left);
        flatten(ptr->right);
    }
};
