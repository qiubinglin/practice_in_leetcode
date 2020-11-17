class Solution:
    def toHex(self, num: int) -> str:
        if num < 0:
            num += 2 ** 32
            
        stack = []
        s = "0123456789abcdef"
        
        while num:
            stack.append(s[num%16])
            num //= 16
            
        if not stack:
            return "0"
        
        stack.reverse()
        return "".join(stack)