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
    int countNodes(TreeNode* root) {
        int cnt=0;
        if(!root) return cnt;
        queue<TreeNode*>q;
        q.push(root);
        while(q.size()){
            auto cur=q.front();
            q.pop();
            cnt++;
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }
        return cnt;
    }
};
