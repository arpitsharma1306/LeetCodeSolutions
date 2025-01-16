class MinStack {
public:
    vector<pair<int,int>>stack;
    long long ptr;
    MinStack() {
        ptr=0;
    }
    
    void push(int val) {
        if(ptr>0){
            if(val<stack[ptr-1].second){
                stack.push_back({val,val});
            }else{
                stack.push_back({val,stack[ptr-1].second});
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
        return stack[ptr-1].first;
    }
    
    int getMin() {
        return stack[ptr-1].second;
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