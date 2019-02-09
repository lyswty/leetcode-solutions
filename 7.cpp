#include <stdexcept>
class Solution {
public:
    int reverse(int x) {
        try{
            string a, b;
            if(x<0){
                a=to_string(x);
                a=a.substr(1);
                b.resize(a.size());
                reverse_copy(a.begin(),a.end(),b.begin());
                x=stoi(b);
                return -x;
            }
            a=to_string(x);
            b.resize(a.size());
            reverse_copy(a.begin(),a.end(),b.begin());
            x=stoi(b);
            return x;
        }
        catch(out_of_range & e){return 0;}
    }
};
