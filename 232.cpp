class MyQueue {
public:
    stack<int>a,b;
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        a.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        while(a.size()>1){
            b.push(a.top());
            a.pop();
        }
        int res=a.top();
        a.pop();
        while(b.size()){
            a.push(b.top());
            b.pop();
        }
        return res;
    }
    
    /** Get the front element. */
    int peek() {
        while(a.size()>1){
            b.push(a.top());
            a.pop();
        }
        int res=a.top();
        while(b.size()){
            a.push(b.top());
            b.pop();
        }
        return res;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return a.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
