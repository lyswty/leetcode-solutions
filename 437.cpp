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
    int cnt=0;
    void getSum(TreeNode* root, int sum){
        if(!root) return;
        sum-=root->val;
        if(sum==0) cnt++;
        getSum(root->left,sum);
        getSum(root->right,sum);
    }
    int pathSum(TreeNode* root, int sum) {
        if(!root) return 0;
        getSum(root,sum);
        pathSum(root->left,sum);
        pathSum(root->right,sum);
        return cnt;
    }
};
