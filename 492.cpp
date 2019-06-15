class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector<int>res(2);
        for(int i=sqrt(area);i<=area;i++) if(area%i==0&&i>=area/i){
            res[0]=i;
            res[1]=area/i;
            break;
        }
        return res;
    }
};
