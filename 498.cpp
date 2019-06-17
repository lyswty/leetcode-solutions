class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int>res;
        if(matrix.empty()||matrix[0].empty()) return res;
        int x=-1,y=0;
        while(x+1!=matrix.size()||y+1!=matrix[0].size()){
            if(x+1<matrix.size()) x++;
            else y++;
            res.emplace_back(matrix[x][y]);
            while(x-1>=0&&y+1<matrix[0].size()){
                x--;
                y++;
                res.emplace_back(matrix[x][y]);
            }
            if(x+1==matrix.size()&&y+1==matrix[0].size()) break;
            if(y+1<matrix[0].size()) y++;
            else x++;
            res.emplace_back(matrix[x][y]);
            while(x+1<matrix.size()&&y-1>=0){
                x++;
                y--;
                res.emplace_back(matrix[x][y]);
            }
        }
        return res;
    }
};
