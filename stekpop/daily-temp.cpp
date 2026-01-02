class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& a) {
        int n = a.size();
        vector<int> ans (n,0);
        stack<int>st;
        int x = 0;
        for(int i=0; i < n ; ++i) {
            while(!st.empty()){
                x=st.top();
                if(a[x]<a[i]) {
                    ans[x]=i-x;
                    st.pop();
                }
                else {
                    break;
                }
            }
            st.push(i);
        }
        return ans;
    }
};
