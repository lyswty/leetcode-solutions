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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return vector<vector<int>>();
        queue<TreeNode*>q;
        q.push(root);
        auto last=root,l=last;
        vector<vector<int>>out;
        vector<int>current;
        while(q.size()){
            auto cur=q.front();
            current.push_back(cur->val);
            q.pop();
            if(cur->left){
                q.push(cur->left);
                l=cur->left;
            }
            if(cur->right){
                q.push(cur->right);
                l=cur->right;
            }
            if(cur==last){
                out.push_back(current);
                current.clear();
                last=l;
            }
        }
        return out;
    }
};
