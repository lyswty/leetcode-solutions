class Solution:
    def issubstring(self,a,b):
        i=0
        j=0
        while i<len(a) and j<len(b):
            if a[i]==b[j]:
                i+=1
                j+=1
            else:
                j+=1
        return i==len(a)
    def findLUSlength(self, strs: List[str]) -> int:
        strs.sort(key=lambda word:len(word),reverse=True)
        for i in range(len(strs)):
            res=True
            for j in range(len(strs)):
                if i==j:
                    continue
                if len(strs[j])<len(strs[i]):
                    break
                if self.issubstring(strs[i],strs[j]):
                    res=False
                    break
            if res:
                return len(strs[i])
        return -1
