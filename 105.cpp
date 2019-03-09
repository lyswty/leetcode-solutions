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
    TreeNode* reconstruct(int prestart,int preend,int instart,int inend,const vector<int>& preorder,const vector<int>& inorder){
        if(prestart>preend) return NULL;
        TreeNode* root=new TreeNode(preorder[prestart]);
        int inroot;
        for(inroot=instart;inorder[inroot]!=root->val;inroot++);
        int preleftstart=prestart+1,inleftstart=instart,inleftend=inroot-1,preleftend=preleftstart+inleftend-inleftstart,prerightstart=preleftend+1,prerightend=preend,inrightstart=inroot+1,inrightend=inend;
        root->left=reconstruct(preleftstart,preleftend,inleftstart,inleftend,preorder,inorder);
        root->right=reconstruct(prerightstart,prerightend,inrightstart,inrightend,preorder,inorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return reconstruct(0,(int)preorder.size()-1,0,(int)inorder.size()-1,preorder,inorder);
    }
};
