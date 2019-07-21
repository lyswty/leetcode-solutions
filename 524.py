class Solution:
    def issubstring(self,a,b):
        i,j=0,0
        while i<len(a) and j<len(b):
            if a[i]==b[j]:
                i+=1
                j+=1
            else:
                i+=1
        return j==len(b)
    def findLongestWord(self, s: str, d: List[str]) -> str:
        d.sort(key=lambda word:(-len(word),word))
        for word in d:
            if self.issubstring(s,word):
                return word
        return ''
