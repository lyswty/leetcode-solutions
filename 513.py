# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findBottomLeftValue(self, root: TreeNode) -> int:
        from queue import Queue
        q=Queue()
        q.put(root)
        last=root
        l=last
        while not q.empty():
            cur=q.get()
            if(cur.right is not None):
                q.put(cur.right)
                l=cur.right
            if(cur.left is not None):
                q.put(cur.left)
                l=cur.left
            if last==cur:
                last=l
        return last.val
