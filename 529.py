class Solution:
    def updateBoard(self, board: List[List[str]], click: List[int]) -> List[List[str]]:
        x,y=click[0],click[1]
        if board[x][y]=='M':
            board[x][y]='X'
            return board
        if board[x][y]=='E':
            cnt=0
            if x and y and board[x-1][y-1]=='M':
                cnt+=1
            if x and board[x-1][y]=='M':
                cnt+=1
            if x and y+1!=len(board[0]) and board[x-1][y+1]=='M':
                cnt+=1
            if y and board[x][y-1]=='M':
                cnt+=1
            if x+1!=len(board) and y and board[x+1][y-1]=='M':
                cnt+=1
            if x+1!=len(board) and y+1!=len(board[0]) and board[x+1][y+1]=='M':
                cnt+=1
            if x+1!=len(board) and board[x+1][y]=='M':
                cnt+=1
            if y+1!=len(board[0]) and board[x][y+1]=='M':
                cnt+=1
            if cnt:
                board[x][y]=str(cnt)
                return board
            board[x][y]='B'
            if x and y and board[x-1][y-1]=='E':
                board=self.updateBoard(board,[x-1,y-1])
            if x and board[x-1][y]=='E':
                board=self.updateBoard(board,[x-1,y])
            if x and y+1!=len(board[0]) and board[x-1][y+1]=='E':
                board=self.updateBoard(board,[x-1,y+1])
            if y and board[x][y-1]=='E':
                board=self.updateBoard(board,[x,y-1])
            if x+1!=len(board) and y and board[x+1][y-1]=='E':
                board=self.updateBoard(board,[x+1,y-1])
            if x+1!=len(board) and y+1!=len(board[0]) and board[x+1][y+1]=='E':
                board=self.updateBoard(board,[x+1,y+1])
            if x+1!=len(board) and board[x+1][y]=='E':
                board=self.updateBoard(board,[x+1,y])
            if y+1!=len(board[0]) and board[x][y+1]=='E':
                board=self.updateBoard(board,[x,y+1])
            return board
