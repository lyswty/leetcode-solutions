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
    TreeNode* out=NULL;
    pair<bool,bool> post(TreeNode* T,TreeNode* p,TreeNode* q){
        pair<bool,bool>res;
        if(!T||out) return res;
        if(T==p) res.first=true;
        if(T==q) res.second=true;
        if(res.first&&res.second){
            out=T;
            return res;
        }
        pair<bool,bool>left=post(T->left,p,q),right=post(T->right,p,q);
        res.first=res.first||left.first||right.first;
        res.second=res.second||right.second||left.second;
        if(res.first&&res.second&&!out) out=T;
        return res;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        post(root,p,q);
        return out;
    }
};
