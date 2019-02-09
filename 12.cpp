class Solution {
public:
    string intToRoman(int num) {
        string out;
        for(int i=0;i<num/1000;i++) out+='M';
        num%=1000;
        if(num/100==9) out+="CM";
        else if(num/100==4) out+="CD";
        else if(num/100>4){
            out+='D';
            for(int i=0;i<num/100-5;i++) out+='C';
        }
        else for(int i=0;i<num/100;i++) out+='C';
        num%=100;
        if(num/10==9) out+="XC";
        else if(num/10==4) out+="XL";
        else if(num/10>4){
            out+='L';
            for(int i=0;i<num/10-5;i++) out+='X';
        }
        else for(int i=0;i<num/10;i++) out+='X';
        num%=10;
        if(num==9) out+="IX";
        else if(num==4) out+="IV";
        else if(num>4){
            out+='V';
            for(int i=0;i<num-5;i++) out+='I';
        }
        else for(int i=0;i<num;i++) out+='I';
        return out;
    }
};
