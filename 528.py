from random import randint
class Solution:
    def __init__(self, w: List[int]):
        self.s=[0]
        for i in w:
            self.s.append(self.s[len(self.s)-1]+i)

    def pickIndex(self) -> int:
        ran=randint(0,self.s[len(self.s)-1]-1)
        left,right=0,len(self.s)-2
        while left<=right:
            mid=(left+right)//2
            if ran<self.s[mid]:
                right=mid-1
            else:
                left=mid+1
        return right

# Your Solution object will be instantiated and called as such:
# obj = Solution(w)
# param_1 = obj.pickIndex()
