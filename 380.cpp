class RandomizedSet {
private:
    unordered_map<int,int>index;
    vector<int>v;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(index.find(val)!=index.end()) return false;
        v.push_back(val);
        index[val]=v.size()-1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(index.find(val)==index.end()) return false;
        swap(v[index[val]],v.back());
        index[v[index[val]]]=index[val];
        index.erase(val);
        v.resize(v.size()-1);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
