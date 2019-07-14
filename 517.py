class Solution:
    def findMinMoves(self, machines: List[int]) -> int:
        sum=0
        for i in range(len(machines)):
            sum+=machines[i]
        if sum%len(machines):
            return -1
        target=sum/len(machines)
        res=0
        balance=0
        for i in range(len(machines)):
            balance+=machines[i]-target
            res=max(res,machines[i]-target,abs(balance))
        return int(res)
