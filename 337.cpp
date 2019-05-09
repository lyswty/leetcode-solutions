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
    unordered_map<TreeNode*,int>mp;
    int rob(TreeNode* root) {
        if(!root) return 0;
        if(!root->left&&!root->right) return root->val;
        if(mp.find(root)!=mp.end()) return mp[root];
        if(!root->left&&root->right) mp[root]=max(rob(root->right->left)+rob(root->right->right)+root->val,rob(root->right));
        else if(root->left&&!root->right) mp[root]=max(rob(root->left->left)+rob(root->left->right)+root->val,rob(root->left));
        else{
            int res=max(rob(root->left->left)+rob(root->left->right)+rob(root->right->left)+rob(root->right->right)+root->val,rob(root->left)+rob(root->right));
            res=max(res,rob(root->left)+rob(root->right->left)+rob(root->right->right));
            res=max(res,rob(root->right)+rob(root->left->left)+rob(root->left->right));
            mp[root]=res;
        }
        return mp[root];
    }
};
