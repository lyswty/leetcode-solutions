# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
from queue import Queue
class Solution:
    def largestValues(self, root: TreeNode) -> List[int]:
        res=[]
        if not root:
            return res
        q=Queue()
        last=l=root
        q.put(root)
        _max=-sys.maxsize-1
        while not q.empty():
            cur=q.get()
            if cur.val>_max:
                _max=cur.val
            if cur.left is not None:
                q.put(cur.left)
                l=cur.left
            if cur.right is not None:
                q.put(cur.right)
                l=cur.right
            if last==cur:
                last=l
                res.append(_max)
                _max=-sys.maxsize-1
        return res
                
