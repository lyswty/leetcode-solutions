class Solution:
    res=0
    def dfs(self,nums,k):
        if k==len(nums):
            for i,num in enumerate(nums):
                if (i+1)%num and num%(i+1):
                    self.res-=1
                    break
            self.res+=1
        else:
            for j in range(k,len(nums)):
                if nums[j]%(k+1) and (k+1)%nums[j]:
                    continue
                nums[k],nums[j]=nums[j],nums[k]
                self.dfs(nums,k+1)
                nums[k],nums[j]=nums[j],nums[k]
    def countArrangement(self, N: int) -> int:
        nums=[i for i in range(1,N+1)]
        self.dfs(nums,0)
        return self.res
