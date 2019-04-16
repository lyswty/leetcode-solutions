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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*>s;
        int cnt=0;
        while(root||s.size()){
            while(root){
                s.push(root);
                root=root->left;
            }
            if(s.size()){
                cnt++;
                root=s.top();
                if(cnt==k) return root->val;
                s.pop();
            }
            root=root->right;
        }
        return -1;
    }
};
