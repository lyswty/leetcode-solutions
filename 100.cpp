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
    bool pre(TreeNode* p,TreeNode* q){
        if(!p&&q||p&&!q) return false;
        if(!p&&!q) return true;
        if(p->val!=q->val) return false;
        return pre(p->left,q->left)&&pre(p->right,q->right);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return pre(p,q);
    }
};
