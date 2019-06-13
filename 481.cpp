class Solution {
public:
    int magicalString(int n) {
        string s="12211";
        int i=3,res=0;
        while(s.size()<n){
            if(s.back()=='1') for(int j=0;j<s[i]-'0';j++) s+='2';
            else for(int j=0;j<s[i]-'0';j++) s+='1';
            i++;
        }
        for(i=0;i<n;i++) if(s[i]=='1') res++;
        return res;
    }
};
