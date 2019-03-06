class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string>output;
        if(s.size()>12) return output;
        for(int i=1;i<4;i++){
            if(i+3>s.size()) break;
            if(s[0]=='0'&&i>1) break;
            int a=stoi(s.substr(0,i));
            if(a>255) break;
            for(int j=1;j<4;j++){
                if(i+j+2>s.size()) break;
                if(s[i]=='0'&&j>1) break;
                int b=stoi(s.substr(i,j));
                if(b>255) break;
                for(int k=1;k<4;k++){
                    if(i+j+k+1>s.size()) break;
                    if(s[i+j]=='0'&&k>1) break;
                    if(s[i+j+k]=='0'&&i+j+k+1<s.size()) continue;
                    int c=stoi(s.substr(i+j,k)),d=stoi(s.substr(i+j+k));
                    if(c>255) break;
                    if(d<=255){
                        string cur;
                        cur+=to_string(a);
                        cur+='.';
                        cur+=to_string(b);
                        cur+='.';
                        cur+=to_string(c);
                        cur+='.';
                        cur+=to_string(d);
                        output.push_back(cur);
                    }
                }
            }
        }
        return output;
    }
};
