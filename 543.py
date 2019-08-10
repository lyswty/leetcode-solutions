# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        res = 0
        def get_height(root):
            nonlocal res
            if not root:
                return 0
            left_height, right_height = get_height(root.left), get_height(root.right)
            res = max(res, left_height + right_height)
            return max(left_height, right_height) + 1
        get_height(root)
        return res
