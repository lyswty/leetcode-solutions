class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        max_length,diff,pos=0,0,{0:-1}
        for i in range(len(nums)):
            if nums[i]:
                diff+=1
            else:
                diff-=1
            if diff in pos:
                max_length=max(max_length,i-pos[diff])
            else:
                pos[diff]=i
        return max_length
