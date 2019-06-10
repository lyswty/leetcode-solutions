class Solution {
public:
    string validIPAddress(string IP) {
        int type=0;
        for(char x:IP){
            if(x=='.'){
                type=4;
                break;
            }
            if(x==':'){
                type=6;
                break;
            }
        }
        if(!type) return "Neither";
        if(!isalnum(IP.back())) return "Neither";
        stringstream ss(IP);
        if(type==4){
            if(IP.size()>15) return "Neither";
            for(int i=1;i<IP.size();i++) if(IP[i]=='.'&&IP[i-1]=='.') return "Neither";
            int cnt=0;
            string cur;
            while(getline(ss,cur,'.')){
                cnt++;
                if(cnt>4) return "Neither";
                for(char x:cur) if(!isdigit(x)) return "Neither";
                if(cur.empty()||cur.size()>3||cur.size()>1&&cur[0]=='0') return "Neither";
                int x=stoi(cur);
                if(x<0||x>255) return "Neither";
            }
            if(cnt!=4) return "Neither";
            return "IPv4";
        }
        else{
            if(IP.size()>39) return "Neither";
            for(int i=0;i<IP.size();i++){
                if(IP[i]=='-') return "Neither";
                if(i&&IP[i-1]==':'&&IP[i]==':') return "Neither";
            }
            int cnt=0;
            string cur;
            while(getline(ss,cur,':')){
                cnt++;
                if(cnt>8) return "Neither";
                if(cur=="0") continue;
                if(cur.size()>4) return "Neither";
                for(char x:cur) if(isalpha(x)&&tolower(x)-'f'>0) return "Neither";
            }
            if(cnt!=8) return "Neither";
            return "IPv6";
        }
    }
};
