class MinStack {
public:
   stack<int> s;
   stack<int> minstack;
    MinStack() {    }
    
    void push(int val) {
        s.push(val);
        if(minstack.empty() ||val<=minstack.top()){
            minstack.push(val);
        }
    }
    
    void pop() {
        if(s.top()==minstack.top())
        {
            minstack.pop();
        }
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minstack.top();
    }
};
