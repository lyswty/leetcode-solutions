class Solution {
public:
    bool isNumber(string s) {
        if(!s.size()) return false;
        int i;
        bool point=false,e=false;
        for(i=0;s[i]==' ';i++);
        if(s[i]=='-'||s[i]=='+') i++;
        if(i>=s.size()) return false;
        if(s[i]=='.'){
            if((!i||!isdigit(s[i-1]))&&(i==s.size()-1||!isdigit(s[i+1]))) return false;
            else point=true;
        }
        else if(!isdigit(s[i])) return false;
        for(int j=i+1;j<s.size();j++){
            if(!isdigit(s[j])){
                if(s[j]=='.'){
                    if(point||(!isdigit(s[j-1])&&(j==s.size()-1||!isdigit(s[j+1])))) return false;
                    else point=true;
                }
                else if(s[j]=='e'){
                    if(e) return false;
                    else if(j+1==s.size()) return false;
                    else if(s[j+1]=='+'||s[j+1]=='-'){
                        if(j+2==s.size()) return false;
                        else if(!isdigit(s[j+2])) return false;
                        else e=point=true;
                        j++;
                    }
                    else if(!isdigit(s[j+1])) return false;
                    else e=point=true;
                }
                else if(s[j]==' '){
                    for(int k=j+1;k<s.size();k++) if(s[k]!=' ') return false;
                    return true;
                }
                else return false;
            }
        }
        return true;
    }
};
