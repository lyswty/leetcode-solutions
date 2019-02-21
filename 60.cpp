class Solution {
public:
    string getPermutation(int n, int k) {
        string s;
        s.resize(n);
        for(int i=1;i<=n;i++) s[i-1]=i+'0';
        k--;
        while(k--){
            int i,min=INT_MAX,minj=-1;
            for(i=n-2;s[i]>s[i+1];i--);
            for(int j=i+1;j<n;j++) if(s[j]>s[i]&&s[j]-'0'<min){
                min=s[j]-'0';
                minj=j;
            }
            swap(s[i],s[minj]);
            sort(s.begin()+i+1,s.end());
        }
        return s;
    }
};
