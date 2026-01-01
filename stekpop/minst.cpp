class MinStack {
    stack<int>st;
    stack<int>minst;
public:

    MinStack() {
        
        
    }
    
    void push(int val) {
        st.push(val); 
        if (minst.empty() || minst.top() >= val) minst.push(val);
       
    }
    
    void pop() {
        int val = st.top();
        st.pop();
        if (!minst.empty() and minst.top() == val) minst.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minst.top();
    }
};
