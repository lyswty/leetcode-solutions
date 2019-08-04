class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        left, right = 0, len(nums) - 1
        while left < right:
            mid = (left + right) // 2
            if (mid - left) % 2:
                if nums[mid] == nums[mid + 1]:
                    right = mid - 1
                else:
                    left = mid + 1
            else:
                if nums[mid - 1] == nums[mid - 2]:
                    left = mid
                else:
                    right = mid - 2
        return nums[left]
