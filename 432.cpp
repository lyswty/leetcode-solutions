class AllOne {
private:
    unordered_map<string,int>keytovalue;
    unordered_map<int,unordered_set<string>>valuetokey;
    int max,min;
public:
    /** Initialize your data structure here. */
    AllOne() {
        max=0,min=INT_MAX;
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if(min==keytovalue[key]&&valuetokey[keytovalue[key]].size()==1) min++;
        if(++keytovalue[key]==1){
            valuetokey[1].insert(key);
            min=1;
        }
        else{
            valuetokey[keytovalue[key]].insert(key);
            valuetokey[keytovalue[key]-1].erase(key);
        }
        if(keytovalue[key]>max) max=keytovalue[key];
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if(keytovalue[key]==min){
            if(keytovalue[key]!=1) min--;
            else if(valuetokey[1].size()==1){
                if(keytovalue.size()==1) min=INT_MAX;
                else min=2;
            }
        }
        if(max==keytovalue[key]&&valuetokey[keytovalue[key]].size()==1) max--;
        if(!--keytovalue[key]){
            valuetokey[1].erase(key);
            keytovalue.erase(key);
        }
        else{
            valuetokey[keytovalue[key]].insert(key);
            valuetokey[keytovalue[key]+1].erase(key);
        }
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if(!max) return "";
        else return *valuetokey[max].begin();
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if(min==INT_MAX) return "";
        else{
            while(valuetokey[min].empty()) min++;
            return *valuetokey[min].begin();
        }
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
