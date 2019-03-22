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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>res;
        stack<TreeNode*>s;
        if(!root) return res;
        s.push(root);
        s.push(root);
        while(s.size()){
            TreeNode* cur=s.top();
            s.pop();
            if(s.size()&&s.top()==cur){
                if(cur->right){
                    s.push(cur->right);
                    s.push(cur->right);
                }
                if(cur->left){
                    s.push(cur->left);
                    s.push(cur->left);
                }
            }
            else res.push_back(cur->val);
        }
        return res;
    }
};
