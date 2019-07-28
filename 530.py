# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    cur,res=-1,sys.maxsize
    def getMinimumDifference(self, root: TreeNode) -> int:
        if not root:
            return
        self.getMinimumDifference(root.left)
        if self.cur!=-1:
            self.res=min(self.res,abs(root.val-self.cur))
        self.cur=root.val
        self.getMinimumDifference(root.right)
        return self.res
