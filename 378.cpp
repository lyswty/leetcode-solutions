class Solution {
public:
    struct node{
        int x,y,val;
        node(){}
        node(int i,int j,int n):x(i),y(j),val(n){}
        friend bool operator<(const node &a,const node &b){
            return a.val>b.val;
        }
    };
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<node>heap;
        heap.push(node(0,0,matrix[0][0]));
        vector<vector<bool>>visited(matrix.size(),vector<bool>(matrix[0].size(),false));
        visited[0][0]=true;
        while(--k){
            node cur=heap.top();
            heap.pop();
            if(cur.x+1<matrix.size()&&!visited[cur.x+1][cur.y]){
                heap.push(node(cur.x+1,cur.y,matrix[cur.x+1][cur.y]));
                visited[cur.x+1][cur.y]=true;
            }
            if(cur.y+1<matrix[0].size()&&!visited[cur.x][cur.y+1]){
                heap.push(node(cur.x,cur.y+1,matrix[cur.x][cur.y+1]));
                visited[cur.x][cur.y+1]=true;
            }
        }
        return heap.top().val;
    }
};
