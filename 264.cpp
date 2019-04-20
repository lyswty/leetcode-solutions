class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<int,vector<int>,greater<int>>q;
        for(int i=0;i<32;i++) for(int j=0;j<20;j++){
            int c=pow(2,i)*pow(3,j);
            if(c<=0) break;
            for(int k=0;k<14;k++){
                int cur=c*pow(5,k);
                if(cur<=0) break;
                q.push(cur);
            }
        }
        for(int i=1;i<n;i++) q.pop();
        return q.top();
    }
};
