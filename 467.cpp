class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int i=0,res=0;
        int *cnt=new int[26];
        fill(cnt,cnt+26,0);
        while(i<p.size()){
            if(!islower(p[i])) i++;
            else{
                int j=i+1,cur=1;
                if(!cnt[p[i]-'a']) cnt[p[i]-'a']=1;
                while(j<p.size()&&islower(p[j])&&(p[j]-p[j-1]==1||p[j-1]=='z'&&p[j]=='a')){
                    cnt[p[j]-'a']=cnt[p[j]-'a']<j-i+1?j-i+1:cnt[p[j]-'a'];
                    j++;
                }
                i=j;
            }
        }
        for(int x=0;x<26;x++) res+=cnt[x];
        return res;
    }
};
