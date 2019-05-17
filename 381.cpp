class RandomizedCollection {
private:
    unordered_map<int,unordered_set<int>>indexes;
    vector<int>v;
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        v.push_back(val);
        indexes[val].insert(v.size()-1);
        return indexes[val].size()==1;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(indexes[val].empty()) return false;
        if(v.back()==val){
            v.resize(v.size()-1);
            indexes[val].erase(v.size());
        }
        else{
            int index=*indexes[val].begin();
            indexes[v.back()].erase(v.size()-1);
            indexes[v.back()].insert(index);
            swap(v.back(),v[index]);
            v.resize(v.size()-1);
            indexes[val].erase(index);
        }
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
