class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        resi={0:-1}
        s=0
        for i in range(len(nums)):
            s=(s+nums[i])%k if k else s+nums[i]
            if s in resi and i-resi[s]>1:
                return True
            resi.setdefault(s,i)
        return False
