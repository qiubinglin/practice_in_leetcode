
方法1

python
(from jianchao-li)
class Solution(object):
    def fractionToDecimal(self, numerator, denominator):
        """
        :type numerator: int
        :type denominator: int
        :rtype: str
        """
        if not numerator:
            return "0"
        ans = ""
        if (numerator > 0) ^ (denominator > 0):
            ans += "-"
        numerator = abs(numerator)
        denominator = abs(denominator)
        ans += str(numerator/denominator)
        r = (numerator%denominator)
        if not r:
            return ans
        
        ans += "."
        r_dict = {}
        while r:
            if r_dict.has_key(r):
                idx = r_dict[r]
                ans = (ans[:idx] + "(" + ans[idx:] + ")")
                break;
            else:
                r_dict[r] = len(ans)
                r *= 10
                ans += str(r/denominator)
                r %= denominator
        return ans