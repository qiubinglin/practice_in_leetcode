class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        start = maxLength = 0
        used = {}
        for i in range(len(s)):
            if s[i] in used and start <= used[s[i]]:
                start = used[s[i]] + 1
            else:
                maxLength = max(maxLength, i - start + 1)
            used[s[i]] = i
        return maxLength