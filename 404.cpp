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
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        int suml=sumOfLeftLeaves(root->left);
        int sumr=sumOfLeftLeaves(root->right);
        if(root->left&&!root->left->right&&!root->left->left) suml+=root->left->val;
        return suml+sumr;
    }
};
