class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        for i in range(len(nums)):
            n = abs(nums[i]) - 1
            if nums[n] > 0:
                nums[n] *= -1
        res = []
        for i, n in enumerate(nums):
            if n > 0:
                res.append(i+1)
        return res