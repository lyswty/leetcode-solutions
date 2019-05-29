/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
class Solution {
public:
    Node* build(vector<vector<int>>&grid,int x,int y,int l){
        bool leaf=true;
        int val=grid[x][y];
        for(int i=x;i<x+l;i++) for(int j=y;j<y+l;j++) if(grid[i][j]!=val){
            leaf=false;
            break;
        }
        Node* res;
        if(leaf) res=new Node(val,leaf,NULL,NULL,NULL,NULL);
        else res=new Node(val,leaf,build(grid,x,y,l/2),build(grid,x,y+l/2,l/2),build(grid,x+l/2,y,l/2),build(grid,x+l/2,y+l/2,l/2));
        return res;
    }
    Node* construct(vector<vector<int>>& grid) {
        if(grid.empty()) return NULL;
        return build(grid,0,0,grid.size());
    }
};
