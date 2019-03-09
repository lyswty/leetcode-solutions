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
    TreeNode* reconstruct(int poststart,int postend,int instart,int inend,const vector<int>& postorder,const vector<int>& inorder){
        if(poststart>postend) return NULL;
        TreeNode* root=new TreeNode(postorder[postend]);
        int inroot;
        for(inroot=instart;inorder[inroot]!=root->val;inroot++);
        int inleftstart=instart,inleftend=inroot-1,inrightstart=inroot+1,inrightend=inend,postrightend=postend-1,postrightstart=postrightend-inrightend+inrightstart,postleftend=postrightstart-1,postleftstart=poststart;
        root->left=reconstruct(postleftstart,postleftend,inleftstart,inleftend,postorder,inorder);
        root->right=reconstruct(postrightstart,postrightend,inrightstart,inrightend,postorder,inorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return reconstruct(0,(int)postorder.size()-1,0,(int)inorder.size()-1,postorder,inorder);
    }
};
