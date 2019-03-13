class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>row(rowIndex+1,1);
        for(int i=1;i<rowIndex/2+1;i++){
            long cur=row[i-1];
            cur=cur*(rowIndex+1-i)/i;
            row[i]=row[rowIndex-i]=cur;
        }
        return row;
    }
};
