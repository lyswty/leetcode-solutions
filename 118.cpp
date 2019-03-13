class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>output;
        for(int i=0;i<numRows;i++){
            vector<int>currow(i+1,1);
            for(int j=1;j<i;j++) currow[j]=output[i-1][j]+output[i-1][j-1];
            output.push_back(currow);
        }
        return output;
    }
};
