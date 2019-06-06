class LFUCache {
private:
    int c,minget;
    unordered_map<int,int>cache,fre;
    unordered_map<int,list<int>>fretokey;
    unordered_map<int,list<int>::iterator>keyit;
public:
    LFUCache(int capacity) {
        c=capacity;
    }
    
    int get(int key) {
        if(cache.find(key)!=cache.end()){
            fretokey[fre[key]++].erase(keyit[key]);
            fretokey[fre[key]].push_front(key);
            keyit[key]=fretokey[fre[key]].begin();
            if(minget==fre[key]-1&&fretokey[fre[key]-1].empty()) minget++;
            return cache[key];
        }
        else return -1;
    }
    
    void put(int key, int value) {
        if(!c) return;
        if(cache.find(key)!=cache.end()){
            cache[key]=value;
            fretokey[fre[key]++].erase(keyit[key]);
            fretokey[fre[key]].push_front(key);
            keyit[key]=fretokey[fre[key]].begin();
            if(minget==fre[key]-1&&fretokey[fre[key]-1].empty()) minget++;
        }
        else{
            if(cache.size()==c){
                int delkey=fretokey[minget].back();
                fretokey[minget].remove(delkey);
                cache.erase(delkey);
                fre.erase(delkey);
                keyit.erase(delkey);
            }
            minget=0;
            cache[key]=value;
            fre[key]=0;
            fretokey[0].push_front(key);
            keyit[key]=fretokey[0].begin();
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
