class Solution {
public:
    struct Qnode{
        int x,y,h;
        Qnode(int _x,int _y,int _h):x(_x),y(_y),h(_h){}
        bool operator<(const Qnode &a)const{
            return h>a.h;
        }
    };
    int trapRainWater(vector<vector<int>>& heightMap) {
        priority_queue<Qnode>heap;
        if(heightMap.size()<3||heightMap[0].size()<3) return 0;
        int row=heightMap.size(),col=heightMap[0].size();
        vector<vector<int>>mark;
        for(int i=0;i<row;i++){
            mark.push_back(vector<int>());
            for(int j=0;j<col;j++) mark[i].push_back(0);
        }
        for(int i=0;i<row;i++){
            heap.push(Qnode(i,0,heightMap[i][0]));
            mark[i][0]=1;
            heap.push(Qnode(i,col-1,heightMap[i][col-1]));
            mark[i][col-1]=1;
        }
        for(int i=1;i<col-1;i++){
            heap.push(Qnode(0,i,heightMap[0][i]));
            mark[0][i]=1;
            heap.push(Qnode(row-1,i,heightMap[row-1][i]));
            mark[row-1][i]=1;
        }
        int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
        int res=0;
        while(heap.size()){
            auto cur=heap.top();
            heap.pop();
            for(int i=0;i<4;i++){
                int x=cur.x+dx[i],y=cur.y+dy[i];
                if(x<0||x>=row||y<0||y>=col||mark[x][y]) continue;
                if(cur.h>heightMap[x][y]){
                    res+=cur.h-heightMap[x][y];
                    heightMap[x][y]=cur.h;
                }
                heap.push(Qnode(x,y,heightMap[x][y]));
                mark[x][y]=1;
            }
        }
        return res;
    }
};
