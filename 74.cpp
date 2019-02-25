class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false;
        int start=0,end=matrix.size()*matrix[0].size()-1;
        while(start<=end){
            int mid=(start+end)/2;
            int x=mid/matrix[0].size(),y=mid%matrix[0].size();
            if(matrix[x][y]<target) start=mid+1;
            else if(matrix[x][y]>target) end=mid-1;
            else return true;
        }
        return false;
    }
};
