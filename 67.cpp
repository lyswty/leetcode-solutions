class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size()<b.size()) swap(a,b);
        bool one=false;
        for(int i=0;i<a.size();i++){
            if(one&&a[a.size()-1-i]=='0'){
                a[a.size()-1-i]='1';
                one=false;
            }
            else if(one&&a[a.size()-1-i]=='1') a[a.size()-1-i]='0';
            if(i<b.size()){
                if(a[a.size()-1-i]=='1'&&b[b.size()-1-i]=='1'){
                    a[a.size()-1-i]='0';
                    one=true;
                }
                else if(a[a.size()-1-i]=='0'&&b[b.size()-1-i]=='1') a[a.size()-1-i]='1';
            }
            else if(!one) break;
        }
        if(one) a='1'+a;
        return a;
    }
};
