class MinStack {
public:

    stack<int> actual, minElement;

    MinStack() {
        actual = stack<int>{};
        minElement = stack<int>{};
    }
    
    void push(int val) {
        actual.push(val);
        if (minElement.empty()) minElement.push(val);
        else if (val <= minElement.top()) minElement.push(val);
    }
    
    void pop() {
        int val = actual.top();
        actual.pop();
        if (val == minElement.top()) minElement.pop();
    }
    
    int top() {
        return actual.top();
    }
    
    int getMin() {
        return minElement.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */