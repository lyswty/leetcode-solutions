# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findFrequentTreeSum(self, root: TreeNode) -> List[int]:
        fre={}
        self.dfs(root,fre)
        res=[]
        maxfre=0
        for key,value in fre.items():
            if value>maxfre:
                res.clear()
                maxfre=value
            if maxfre==value:
                res.append(key)
        return res
    def dfs(self,root,fre):
        if not root:
            return 0
        res=self.dfs(root.left,fre)+self.dfs(root.right,fre)+root.val
        if res not in fre:
            fre[res]=1
        else:
            fre[res]+=1
        return res
