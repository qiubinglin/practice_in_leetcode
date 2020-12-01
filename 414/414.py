class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        a = b = c = float('-inf')
        for num in nums:
            if num not in (a, b, c):
                if num > a:
                    a, b, c = num, a, b
                elif num > b:
                    a, b, c = a, num, b
                elif num > c:
                    a, b, c = a, b, num
        return c if float('-inf') not in (a, b, c) else a