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
    void DFS(string &path,TreeNode* root,vector<string>&res){
        if(path.size()) path+="->";
        path+=to_string(root->val);
        if(!root->left&&!root->right) res.push_back(path);
        else{
            string start=path;
            if(root->left){
                DFS(path,root->left,res);
                path=start;
            }
            if(root->right){
                DFS(path,root->right,res);
                path=start;
            }
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>res;
        if(!root) return res;
        string path;
        DFS(path,root,res);
        return res;
    }
};
