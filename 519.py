from random import randint
class Solution:

    def __init__(self, n_rows: int, n_cols: int):
        self.rows=n_rows
        self.cols=n_cols
        self.sum=n_rows*n_cols
        self.mp={}
        self.cnt=0

    def flip(self) -> List[int]:
        cur=randint(0,self.sum-self.cnt-1)
        while self.mp.get(cur):
            cur=self.mp[cur]
        self.mp[cur]=self.sum-self.cnt-1
        self.cnt+=1
        return [cur//self.cols,cur%self.cols]

    def reset(self) -> None:
        self.cnt=0
        self.mp.clear()


# Your Solution object will be instantiated and called as such:
# obj = Solution(n_rows, n_cols)
# param_1 = obj.flip()
# obj.reset()
