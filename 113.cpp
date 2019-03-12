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
    void DFS(TreeNode* T,int sum,int cur,vector<vector<int>>&paths,vector<int>&path){
        if(!T) return;
        cur+=T->val;
        path.push_back(T->val);
        if(!T->left&&!T->right&&cur==sum) paths.push_back(path);
        if(T->left){
            DFS(T->left,sum,cur,paths,path);
            path.pop_back();
        }
        if(T->right){
            DFS(T->right,sum,cur,paths,path);
            path.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>>paths;
        vector<int>path;
        DFS(root,sum,0,paths,path);
        return paths;
    }
};
