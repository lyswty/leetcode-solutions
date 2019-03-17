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
    string cur;
    int sum=0;
    void DFS(TreeNode* root){
        cur.push_back(root->val+'0');
        if(!root->left&&!root->right) sum+=stoi(cur);
        if(root->left){
            DFS(root->left);
            cur.pop_back();
        }
        if(root->right){
            DFS(root->right);
            cur.pop_back();
        }
    }
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        DFS(root);
        return sum;
    }
};
