class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>res;
        for(int i=0;i<numbers.size();i++){
            auto it=lower_bound(numbers.begin()+i+1,numbers.end(),target-numbers[i]);
            if(it!=numbers.end()&&(*it)==target-numbers[i]){
                res.push_back(i+1);
                res.push_back(distance(numbers.begin(),it)+1);
                break;
            }
        }
        return res;
    }
};
