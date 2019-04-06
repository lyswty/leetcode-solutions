class Solution {
public:
    void DFS(vector<vector<char>>& grid,vector<vector<bool>>& vis,int x,int y){
        vis[x][y]=true;
        if(x!=0&&!vis[x-1][y]&&grid[x-1][y]=='1') DFS(grid,vis,x-1,y);
        if(x+1!=grid.size()&&!vis[x+1][y]&&grid[x+1][y]=='1') DFS(grid,vis,x+1,y);
        if(y!=0&&!vis[x][y-1]&&grid[x][y-1]=='1') DFS(grid,vis,x,y-1);
        if(y+1!=grid[0].size()&&!vis[x][y+1]&&grid[x][y+1]=='1') DFS(grid,vis,x,y+1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt=0;
        if(grid.empty()) return cnt;
        vector<vector<bool>>vis(grid.size(),vector<bool>(grid[0].size(),false));
        for(int i=0;i<grid.size();i++) for(int j=0;j<grid[0].size();j++) if(!vis[i][j]&&grid[i][j]=='1'){
            cnt++;
            DFS(grid,vis,i,j);
        }
        return cnt;
    }
};
