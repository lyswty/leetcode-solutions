class Solution {
public:
    int maxarray(vector<int>&colmatrix,int k){
        int sum=INT_MIN;
        for(int i=0;i<colmatrix.size();i++){
            int cur=0;
            for(int j=i;j<colmatrix.size();j++){
                cur+=colmatrix[j];
                if(cur<=k) sum=max(sum,cur);
            }
        }
        return sum;
    }
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int res=INT_MIN;
        for(int i=0;i<matrix.size();i++){
            vector<int>colmatrix(matrix[0].size(),0);
            for(int j=i;j<matrix.size();j++){
                for(int m=0;m<matrix[0].size();m++) colmatrix[m]+=matrix[j][m];
                res=max(maxarray(colmatrix,k),res);
            }
        }
        return res;
    }
};
