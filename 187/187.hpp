
方法1

python
(from alizee56)
class Solution(object):
    def findRepeatedDnaSequences(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        sequences = collections.defaultdict(int)
        for i in range(len(s)):
            sequences[s[i:i+10]] += 1
        return [key for key, value in sequences.iteritems() if value > 1]