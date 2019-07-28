from bisect import bisect_left
class Solution:
    def findPairs(self, nums: List[int], k: int) -> int:
        nums.sort()
        vis=set()
        res=0
        for i in range(len(nums)):
            if nums[i] in vis:
                continue
            index=bisect_left(nums,nums[i]+k,i+1)
            if index<len(nums) and nums[index]==nums[i]+k:
                res+=1
            vis.add(nums[i])
        return res
