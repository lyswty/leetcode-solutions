class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m>n) swap(m,n);
        long long a=1,A=m+n-2,b=1;
        for(int i=0;i<m-1;i++){
            a*=A;
            A--;
        }
        for(int i=1;i<m;i++) b*=i;
        return a/b;
    }
};
