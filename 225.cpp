class MyStack {
public:
    queue<int>q1,q2;
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        if(q2.empty()) q1.push(x);
        else q2.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int res;
        if(q1.size()){
            while(q1.size()>1){
                q2.push(q1.front());
                q1.pop();
            }
            res=q1.front();
            q1.pop();
        }
        else{
            while(q2.size()>1){
                q1.push(q2.front());
                q2.pop();
            }
            res=q2.front();
            q2.pop();
        }
        return res;
    }
    
    /** Get the top element. */
    int top() {
        int res;
        if(q1.size()){
            while(q1.size()>1){
                q2.push(q1.front());
                q1.pop();
            }
            res=q1.front();
            q1.pop();
            q2.push(res);
        }
        else{
            while(q2.size()>1){
                q1.push(q2.front());
                q2.pop();
            }
            res=q2.front();
            q2.pop();
            q1.push(res);
        }
        return res;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty()&&q2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
