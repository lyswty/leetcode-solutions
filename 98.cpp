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
    long M=LONG_MIN;
    bool in(TreeNode* root){
        if(!root) return true;
        if(!in(root->left)) return false;
        if(root->left&&root->left->val>=root->val) return false;
        if(root->right&&root->right->val<=root->val) return false;
        if(root->val<=M) return false;
        M=root->val;
        if(!in(root->right)) return false;
        return true;
    }
    bool isValidBST(TreeNode* root) {
        return in(root);
    }
};
