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
    int M=INT_MIN;
    int maxSum(TreeNode* T){
        if(!T) return 0;
        int ml=maxSum(T->left),mr=maxSum(T->right),Max=ml+T->val;
        if(mr+T->val>Max) Max=mr+T->val;
        if(T->val>Max) Max=T->val;
        if(Max>M) M=Max;
        if(T->left&&ml>M) M=ml;
        if(T->right&&mr>M) M=mr;
        if(mr+ml+T->val>M) M=mr+ml+T->val;
        return Max;
    }
    int maxPathSum(TreeNode* root) {
        maxSum(root);
        return M;
    }
};
