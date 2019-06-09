class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        vector<int>c(n1+1,0),inx(n1+1,0);
        int j=0,cnt=0;
        for(int k=1;k<=n1;k++){
            for(int i=0;i<s1.size();i++) if(s1[i]==s2[j]){
                j++;
                if(j==s2.size()){
                    j=0;
                    cnt++;
                }
            }
            c[k]=cnt;
            inx[k]=j;
            for(int i=0;i<k;i++) if(inx[i]==j){
                int d=k-i,n=(n1-i)/d;
                return ((c[k]-c[i])*n+c[i+(n1-i)%d])/n2;
            }
        }
        return c[n1]/n2;
    }
};
