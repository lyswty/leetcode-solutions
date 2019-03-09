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
    bool pre(TreeNode* root1,TreeNode* root2){
        if(!root1&&!root2) return true;
        if(!root1&&root2||root1&&!root2||root1->val!=root2->val) return false;
        return pre(root1->left,root2->right)&&pre(root1->right,root2->left);
    }
    bool isSymmetric(TreeNode* root) {
        return pre(root,root);
    }
};
