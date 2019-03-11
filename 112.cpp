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
    int cursum=0;
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        cursum+=root->val;
        int backup=cursum;
        if(!root->left&&!root->right) return cursum==sum;
        if(!root->left&&root->right) return hasPathSum(root->right,sum);
        if(root->left&&!root->right) return hasPathSum(root->left,sum);
        if(hasPathSum(root->left,sum)) return true;
        cursum=backup;
        return hasPathSum(root->right,sum);
    }
};
