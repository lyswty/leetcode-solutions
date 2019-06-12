class Solution {
public:
    string smallestGoodBase(string n) {
        long long num=stoll(n);
        for(int m=log2(num+1);m>=2;m--){
            long long left=2,right=pow(num,1.0/(m-1))+1;
            while(left<right){
                long long mid=(left+right)/2,sum=0;
                for(int j=0;j<m;j++) sum=sum*mid+1;
                if(sum==num) return to_string(mid);
                if(sum<num) left=mid+1;
                else right=mid;
            }
        }
        return to_string(num-1);
    }
};
