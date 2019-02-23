class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int one=1;
        for(int i=digits.size()-1;i>=0;i--){
            if(digits[i]+one==10) digits[i]=0;
            else{
                digits[i]+=one;
                one=0;
                break;
            }
        }
        if(one) digits.insert(digits.begin(),1);
        return digits;
    }
};
