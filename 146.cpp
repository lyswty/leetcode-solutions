class LRUCache {
public:
    int C;
    unordered_map<int,list<pair<int,int>>::iterator>mp;
    list<pair<int,int>>li;
    int cur;
    LRUCache(int capacity) {
        C=capacity;
        cur=0;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            li.splice(li.begin(),li,mp[key]);
            return mp[key]->second;
        }
        else return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            mp[key]->second=value;
            get(key);
        }
        else if(cur<C){
            cur++;
            li.push_front(pair<int,int>(key,value));
            mp[key]=li.begin();
        }
        else{
            li.push_front(pair<int,int>(key,value));
            mp[key]=li.begin();
            mp.erase(li.back().first);
            li.pop_back();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
