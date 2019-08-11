class Solution:
    def removeBoxes(self, boxes: List[int]) -> int:
        dp = [[[0] * len(boxes) for i in range(len(boxes))] for i in range(len(boxes))]
        def cal(i, j, k):
            if i > j:
                return 0
            if dp[i][j][k] != 0:
                return dp[i][j][k]
            while i < j and boxes[i] == boxes[i + 1]:
                i += 1
                k += 1
            res = (k + 1) ** 2 + cal(i + 1, j, 0)
            for m in range(i + 1, j + 1):
                if boxes[m] == boxes[i]:
                    res = max(res, cal(i + 1, m - 1, 0) + cal(m, j ,k + 1))
            dp[i][j][k] = res
            return dp[i][j][k]
        return cal(0, len(boxes) - 1, 0)
