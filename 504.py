class Solution:
    def convertToBase7(self, num: int) -> str:
        if not num:
            return "0"
        res=""
        absnum=abs(num)
        while absnum:
            res+=str(absnum%7)
            cur=absnum/7
            absnum=int(cur)
        return res[::-1] if num>0 else '-'+res[::-1]
