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
    vector<TreeNode*> gt(int begin,int end){
        vector<TreeNode*>out;
        if(begin>end) out.push_back(NULL);
        else for(int i=begin;i<=end;i++){
            vector<TreeNode*>L=gt(begin,i-1),R=gt(i+1,end);
            for(TreeNode* l:L) for(TreeNode*r:R){
                TreeNode* root=new TreeNode(i);
                root->left=l;
                root->right=r;
                out.push_back(root);
            }
        }
        return out;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(!n) return vector<TreeNode*>();
        vector<TreeNode*>out=gt(1,n);
        return out;
    }
};
