class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int res=0;
        for(int i=0;i<grid.size();i++) for(int j=0;j<grid[0].size();j++) if(grid[i][j]){
            int cur=0;
            if(!i||!grid[i-1][j]) cur++;
            if(i+1==grid.size()||!grid[i+1][j]) cur++;
            if(!j||!grid[i][j-1]) cur++;
            if(j+1==grid[0].size()||!grid[i][j+1]) cur++;
            res+=cur;
        }
        return res;
    }
};
