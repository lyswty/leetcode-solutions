class Solution {
public:
    int compress(vector<char>& chars) {
        int i=1,res=0,chan=i;
        if(chars.size()==1||chars[chars.size()-1]!=chars[chars.size()-2]) res=1;
        while(i<chars.size()){
            int cnt=1;
            while(i<chars.size()&&chars[i]==chars[i-1]) i++,cnt++;
            if(cnt!=1){
                string cur=to_string(cnt);
                for(int j=0;j<cur.size();j++) chars[chan++]=cur[j];
                res+=1+cur.size();
            }
            else res++;
            if(i<chars.size()) chars[chan++]=chars[i++];
        }
        return res;
    }
};
