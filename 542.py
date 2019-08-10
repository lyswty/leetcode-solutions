from queue import Queue
class Solution:
    def updateMatrix(self, matrix: List[List[int]]) -> List[List[int]]:
        if not len(matrix) or not len(matrix[0]):
            return [[]]
        op = ((-1, 0), (1, 0), (0, -1), (0, 1))
        q = Queue()
        res = [[-1 for i in range(len(matrix[0]))] for i in range(len(matrix))]
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if not matrix[i][j]:
                    q.put([i, j])
                    res[i][j] = 0
        while q.qsize():
            cur = q.get()
            set_value = res[cur[0]][cur[1]] + 1
            for o in op:
                x, y = cur[0] + o[0], cur[1] + o[1]
                if x < 0 or y < 0 or x >= len(matrix) or y >= len(matrix[0]) or res[x][y] != -1:
                    continue
                q.put([x, y])
                res[x][y] = set_value
        return res        
