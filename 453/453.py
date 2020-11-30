class Solution:
    def minMoves(self, nums: List[int]) -> int:
        minnum = min(nums)
        moves = 0
        for i in range(len(nums)):
            moves += nums[i] - minnum
        return moves