class MinStack {
public:
    vector<pair<int,int>>stack;
    int ptr;
    MinStack() {
        ptr=-1;
    }
    
    void push(int val) {
        if(ptr>=0){
            if(val<stack[ptr].second){
                stack.push_back({val,val});
            }else{
                stack.push_back({val,stack[ptr].second});
            }
        }else{
            stack.push_back({val,val});
        }
        ptr++;
    }
    
    void pop() {
        stack.pop_back();
        ptr--;
    }
    
    int top() {
        return stack[ptr].first;
    }
    
    int getMin() {
        return stack[ptr].second;
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