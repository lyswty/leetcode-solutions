class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int i=0;
        while(i<data.size()){
            if((data[i]>>7)%2==0) i++;
            else if((data[i]>>6)%2==0) return false;
            else if((data[i]>>5)%2==0){
                if(i+1>=data.size()||data[i+1]>>6!=2) return false;
                i+=2;
            }
            else if((data[i]>>4)%2==0){
                if(i+2>=data.size()||data[i+1]>>6!=2||data[i+2]>>6!=2) return false;
                i+=3;
            }
            else if((data[i]>>3)%2==0){
                if(i+3>=data.size()||data[i+1]>>6!=2||data[i+2]>>6!=2||data[i+3]>>6!=2) return false;
                i+=4;
            }
            else return false;
        }
        return true;
    }
};
