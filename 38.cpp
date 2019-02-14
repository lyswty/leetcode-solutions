class Solution {
public:
    string countAndSay(int n) {
        string a="1",b;
        for(int i=1;i<n;i++){
            int j=0;
            while(j<a.size()){
                int k;
                for(k=j;k<a.size()&&a[k]==a[j];k++);
                b+=to_string(k-j);
                b+=a[j];
                j=k;
            }
            a=b;
            b="";
        }
        return a;
    }
};
