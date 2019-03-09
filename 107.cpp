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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root) return vector<vector<int>>();
        deque<vector<int>>out;
        vector<int>current;
        queue<TreeNode*>q;
        q.push(root);
        TreeNode *last=root,*l=last;
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
                last=l;
                out.push_front(current);
                current.clear();
            }
        }
        return vector<vector<int>>(out.begin(),out.end());
    }
};
