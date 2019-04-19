class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int>res;
        for(int i=0;i<input.size();i++){
            if(input[i]=='+'||input[i]=='-'||input[i]=='*'){
                auto o1=diffWaysToCompute(input.substr(0,i));
                auto o2=diffWaysToCompute(input.substr(i+1));
                for(auto i1:o1) for(auto i2:o2){
                    switch(input[i]){
                        case '+':res.push_back(i1+i2);break;
                        case '-':res.push_back(i1-i2);break;
                        case '*':res.push_back(i1*i2);
                    }
                }
            }
        }
        if(res.empty()) res.push_back(stoi(input));
        return res;
    }
};
