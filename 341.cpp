/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
private:
    stack<int>res;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        stack<NestedInteger>s;
        for(auto l:nestedList) s.push(l);
        while(s.size()){
            if(s.top().isInteger()){
                res.push(s.top().getInteger());
                s.pop();
            }
            else{
                auto List=s.top().getList();
                s.pop();
                for(auto l:List) s.push(l);
            }
        }
    }

    int next() {
        int rt=res.top();
        res.pop();
        return rt;
    }

    bool hasNext() {
        return res.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
