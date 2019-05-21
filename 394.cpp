class Solution {
public:
    string decodeString(string s) {
        if(s.empty()) return "";
        if(isalpha(s[0])){
            int i;
            for(i=0;i<s.size()&&isalpha(s[i]);i++);            
            return s.substr(0,i)+decodeString(s.substr(i));
        }
        int cnt=1;
        int i,j;
        for(i=1;isdigit(s[i]);i++);
        int time=stoi(s.substr(0,i));
        for(j=i+1;cnt;j++){
            if(s[j]=='[') cnt++;
            if(s[j]==']') cnt--;
        }
        j--;
        string res,cur=decodeString(s.substr(i+1,j-i-1));
        while(time--) res+=cur;
        return res+decodeString(s.substr(j+1));
    }
};
