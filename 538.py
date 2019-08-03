# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def __init__(self):
        self.last = 0
    def convertBST(self, root: TreeNode) -> TreeNode:
        if not root:
            return root
        self.convertBST(root.right)
        root.val += self.last
        self.last = root.val
        self.convertBST(root.left)
        return root
