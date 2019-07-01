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
    void in(TreeNode* root,vector<int>&res,int& maxcnt,int& cnt,long& last){
        if(!root) return;
        in(root->left,res,maxcnt,cnt,last);
        if(root->val==last) cnt++;
        else{
            if(cnt>maxcnt){
                res.clear();
                maxcnt=cnt;
            }
            if(cnt==maxcnt&&cnt) res.emplace_back(last);
            cnt=1;
            last=root->val;
        }
        in(root->right,res,maxcnt,cnt,last);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int>res;
        int maxcnt=0,cnt=0;
        long last=LONG_MAX;
        in(root,res,maxcnt,cnt,last);
        if(cnt>maxcnt){
            res.clear();
            maxcnt=cnt;
        }
        if(cnt==maxcnt&&cnt) res.emplace_back(last);
        return res;
    }
};
