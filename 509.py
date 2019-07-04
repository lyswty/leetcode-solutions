class Solution:
    def fib(self, N: int) -> int:
        if N==0:
            return 0
        elif N==1:
            return 1
        last=0
        cur=1
        for i in range(2,N+1):
            last,cur=cur,last+cur
        return cur
