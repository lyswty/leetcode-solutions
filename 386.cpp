class Solution {
public:
    vector<int> lexicalOrder(int n) {
        int cur=1;
        vector<int>res;
        while(res.size()<n){
            res.push_back(cur);
            if(cur*10<=n) cur*=10;
            else{
                if(cur>=n) cur/=10;
                cur+=1;
                while(cur%10==0) cur/=10;
            }
        }
        return res;
    }
};
