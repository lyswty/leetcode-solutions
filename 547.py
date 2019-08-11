class Solution:
    def findCircleNum(self, M: List[List[int]]) -> int:
        n = len(M)
        res = set()
        father = [-1] * n
        for i in range(n):
            father[i] = i
        def find(x):
            if father[x] == x:
                return x
            father[x] = find(father[x])
            return father[x]
        for i in range(n):
            for j in range(i + 1, n):
                if M[i][j]:
                    father_i, father_j = find(i), find(j)
                    if father_i != father_j:
                        father[father_j] = father_i
        for i in range(n):
            res.add(find(i))
        return len(res)
