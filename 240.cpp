class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()||matrix[0].empty()) return false;
        for(int i=0;i<matrix.size();i++){
            auto it=lower_bound(matrix[i].begin(),matrix[i].end(),target);
            if(it!=matrix[i].end()&&*it==target) return true;
        }
        return false;
    }
};
