class Solution:
    def checkPerfectNumber(self, num: int) -> bool:
        if num<=1:
            return False
        sum=1
        k=math.sqrt(num)        
        for i in range(2,int(k)+1,2):
            if num%i==0:
                sum+=i+int(num/i)
        return sum==num
