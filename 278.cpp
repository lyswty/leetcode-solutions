// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long start=1,end=n;
        while(start<end){
            long mid=(start+end)/2;
            if(isBadVersion(mid)) end=mid;
            else start=mid+1;
        }
        return end;
    }
};
