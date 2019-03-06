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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>v;
        if(!root) return v;
        stack<TreeNode*>s;
        while(root||s.size()){
            while(root){
                s.push(root);
                root=root->left;
            }
            if(s.size()){
                root=s.top();
                v.push_back(root->val);
                s.pop();
            }
            root=root->right;
        }
        return v;
    }
};
