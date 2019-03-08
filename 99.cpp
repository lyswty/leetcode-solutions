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
    long cur1=LONG_MIN,cur2=LONG_MAX;
    TreeNode* c1,*c2;
    bool flag=false;
    void in(TreeNode* root){
        if(!root) return;
        in(root->left);
        if(!flag&&root->val>cur1){
            cur1=root->val;
            c1=root;
        }
        else if(root->val>cur1) return;
        else{
            flag=true;
            cur2=root->val;
            c2=root;
        }
        in(root->right);
    }
    void recoverTree(TreeNode* root) {
        in(root);
        swap(c1->val,c2->val;)
    }
};
