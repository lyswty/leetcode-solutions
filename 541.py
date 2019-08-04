class Solution:
    def reverseStr(self, s: str, k: int) -> str:
        res = ""
        i = 0
        while i <= len(s):
            res += s[i:min(i + k, len(s))][::-1]
            i += k
            if i >= len(s):
                break
            res += s[i:min(i + k, len(s))]
            i += k
        return res
