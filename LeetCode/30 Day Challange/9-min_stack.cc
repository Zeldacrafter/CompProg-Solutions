class MinStack {
public:
    stack<pair<int, int>> s;
    
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        s.emplace(s.empty() ? x : min(x, s.top().first), x);
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top().second;
    }
    
    int getMin() {
        return s.top().first;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
