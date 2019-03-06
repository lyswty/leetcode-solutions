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
    int numTrees(int n) {
        int *dp=new int[n+1];
        dp[0]=1;
        if(n>=1) dp[1]=1;
        if(n>=2) dp[2]=2;
        for(int i=3;i<=n;i++){
            dp[i]=0;
            for(int j=1;j<=i/2;j++) dp[i]+=dp[j-1]*dp[i-j]*2;
            if(i%2) dp[i]+=dp[i/2]*dp[i/2];
        }
        return dp[n];
    }
};
