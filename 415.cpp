class Solution {
public:
    string addStrings(string num1, string num2) {
        int ten=0;
        if(num1.size()<num2.size()) swap(num1,num2);
        for(int i=0;num1.size()-i>=1;i++){
            int cur;
            if((int)num2.size()-i>=1) cur=num1[num1.size()-1-i]-'0'+num2[num2.size()-1-i]-'0'+ten;
            else cur=num1[num1.size()-1-i]-'0'+ten;
            ten=cur/10;
            num1[num1.size()-1-i]=cur%10+'0';
        }
        if(ten) num1='1'+num1;
        return num1;
    }
};
