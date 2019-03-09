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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return vector<vector<int>>();
        queue<TreeNode*>q;
        q.push(root);
        auto last=root,l=last;
        int level=1;
        vector<vector<int>>out;
        deque<int>current;
        while(q.size()){
            auto cur=q.front();
            if(level%2) current.push_back(cur->val);
            else current.push_front(cur->val);
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
                out.push_back(vector<int>(current.begin(),current.end()));
                current.clear();
                last=l;
                level++;
            }
        }
        return out;
    }
};
