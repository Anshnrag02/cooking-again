class Solution {
public:
    int largestRectangleArea(vector<int>& a) {
        stack<int>st;
        int maxar=0,temp;
        a.push_back(-1);
        int n = a.size();
        for(int i = 0 ; i < n ; ++i){
            while(!st.empty() and a[st.top()]>a[i]){
                temp = st.top();
                st.pop();
                int ar = st.empty()? a[temp] * i : a[temp] * (i-st.top() - 1);
                maxar = max(ar ,maxar); 
                
            }
            st.push(i);
        }
        return maxar;
    }
};
