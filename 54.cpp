class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>out;
        if(matrix.empty()||matrix[0].empty()) return out;
        int left=0,right=matrix[0].size()-1,top=0,end=matrix.size()-1;
        while(left<=right&&top<=end){
            for(int i=left;i<=right;i++) out.push_back(matrix[top][i]);
            for(int i=top+1;i<=end;i++) out.push_back(matrix[i][right]);
            if(top!=end) for(int i=right-1;i>=left;i--) out.push_back(matrix[end][i]);
            if(right!=left) for(int i=end-1;i>top;i--) out.push_back(matrix[i][left]);
            left++,right--,top++,end--;
        }
        return out;
    }
};
