class MinStack {
public:
    /** initialize your data structure here. */
    stack<int>s;
    int curmin;
    unordered_map<int,int>formmin,cnt;
    MinStack() {
        
    }
    
    void push(int x) {
        s.push(x);
        cnt[x]++;
        if(s.size()==1) curmin=x;
        else if(x<curmin){
            formmin[x]=curmin;
            curmin=x;
        }
    }
    
    void pop() {
        cnt[s.top()]--;
        if(s.top()==curmin&&!cnt[curmin]) curmin=formmin[curmin];
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return curmin;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
