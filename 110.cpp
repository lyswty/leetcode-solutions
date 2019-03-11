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
    int getheight(TreeNode* root){
        if(!root) return 0;
        int hl=getheight(root->left)+1,hr=getheight(root->right)+1;
        return hl>hr?hl:hr;
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        if(abs(getheight(root->left)-getheight(root->right))>1) return false;
        return isBalanced(root->left)&&isBalanced(root->right);
    }
};
