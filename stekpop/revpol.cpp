class Solution {
public:
    int evalRPN(vector<string>& a) {
        stack<int>st;
        for(string x:a){
            if(x== "+" || x== "-" || x== "*" || x== "/" ){
                int t2=st.top();
                st.pop();
                int t1=st.top();
                st.pop();
                if (x== "+") {
                    st.push(t1+t2);
                }
                if (x== "-") {
                    st.push(t1-t2);
                }
                if (x== "*") {
                    st.push(t1*t2);
                }
                if (x== "/") {
                    st.push(t1/t2);
                }
            }
            else {
                st.push(stoi(x));
            }
        }
        return st.top();
    }
};
