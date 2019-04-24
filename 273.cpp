class Solution {
public:
    string numberToWords(int num) {
        string twenty[20]={"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
        string tens[10]={"","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
        if(!num) return "Zero";
        string res;
        if(num>=1000000000){
            int x=num/1000000000;
            if(x>=100){
                res+=twenty[x/100];
                res+=" Hundred ";
                x%=100;
            }
            if(x>=20){
                res+=tens[x/10];
                res+=' ';
                x%=10;
                res+=twenty[x];
                if(x) res+=' ';
            }
            else{
                res+=twenty[x];
                if(x) res+=' ';
            }
            res+="Billion";
            num%=1000000000;
            if(num) res+=' ';
        }
        if(num>=1000000){
            int x=num/1000000;
            if(x>=100){
                res+=twenty[x/100];
                res+=" Hundred ";
                x%=100;
            }
            if(x>=20){
                res+=tens[x/10];
                res+=' ';
                x%=10;
                res+=twenty[x];
                if(x) res+=' ';
            }
            else{
                res+=twenty[x];
                if(x) res+=' ';
            }
            res+="Million";
            num%=1000000;
            if(num) res+=' ';
        }
        if(num>=1000){
            int x=num/1000;
            if(x>=100){
                res+=twenty[x/100];
                res+=" Hundred ";
                x%=100;
            }
            if(x>=20){
                res+=tens[x/10];
                res+=' ';
                x%=10;
                res+=twenty[x];
                if(x) res+=' ';
            }
            else{
                res+=twenty[x];
                if(x) res+=' ';
            }
            res+="Thousand";
            num%=1000;
            if(num) res+=' ';
        }
        if(num>=100){
            res+=twenty[num/100];
            res+=" Hundred";
            if(num%100) res+=' ';
            num%=100;
        }
        if(num>=20){
            res+=tens[num/10];
            if(num%10) res+=' ';
            num%=10;
            res+=twenty[num];
        }
        else res+=twenty[num];
        return res;
    }
};
