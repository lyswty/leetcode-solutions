class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int>v(num1.size()+num2.size(),0);
        for(int i=0;i<num1.size();i++) for(int j=0;j<num2.size();j++) v[(num1.size()-i-1)+(num2.size()-j-1)]+=(num1[i]-'0')*(num2[j]-'0');
        string out;
        out.resize(v.size());
        for(int i=0;i<v.size();i++){
            if(v[i]/10) v[i+1]+=v[i]/10;
            out[out.size()-i-1]=v[i]%10+'0';
        }
        for(int i=0;i<=out.size();i++) if(i==out.size()||out[i]!='0'){
            out=out.substr(i);
            break;
        }
        if(!out.size()) out+='0';
        return out;
    }
};
