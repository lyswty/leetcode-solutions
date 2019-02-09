class Solution {
public:
    int myAtoi(string str) {
        int i,j,sum=0;
        bool neg=false;
        for(i=0;i<str.size()&&str[i]==' ';i++);
        if(i==str.size()||(str[i]!='+'&&str[i]!='-'&&!isdigit(str[i]))||(((str[i]=='+')||(str[i]=='-'))&&((i+1==str.size())||(!isdigit(str[i+1]))))) return 0;
        if(!isdigit(str[i])){
            if(str[i]=='-') neg=true;
            i++;
        }
        for(j=i;j<str.size()&&isdigit(str[j]);j++);
        for(;i<j;i++){
            if(neg) sum-=(str[i]-'0')*pow(10,j-i-1);
            else sum+=(str[i]-'0')*pow(10,j-i-1);
            if(neg&&sum>0) return INT_MIN;
            if(!neg&&sum<0) return INT_MAX;
        }
        return sum;
    }
};
