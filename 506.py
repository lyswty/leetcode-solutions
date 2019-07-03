class Solution:
    def findRelativeRanks(self, nums: List[int]) -> List[str]:
        tmp=[x for x in nums]
        tmp.sort(reverse=True)
        dic={}
        for r in range(0,len(tmp)):
            if r==0:
                dic[tmp[r]]="Gold Medal"
            elif r==1:
                dic[tmp[r]]="Silver Medal"
            elif r==2:
                dic[tmp[r]]="Bronze Medal"
            else:
                dic[tmp[r]]=str(r+1)
        return [dic[x] for x in nums]
