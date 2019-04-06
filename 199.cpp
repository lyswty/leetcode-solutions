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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
        if(!root) return res;
        queue<TreeNode*>q;
        q.push(root);
        auto last=root,l=root;
        while(q.size()){
            auto cur=q.front();
            q.pop();
            if(cur->left){
                q.push(cur->left);
                l=cur->left;
            }
            if(cur->right){
                q.push(cur->right);
                l=cur->right;
            }
            if(last==cur){
                res.push_back(last->val);
                last=l;
            }
        }
        return res;
    }
};
