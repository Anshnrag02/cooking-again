class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans="";
        stack<int>st;
        int n = s.length();
        vector<bool>rm(n,false);
        for(int i = 0 ; i < n ; ++i) {
            if (s[i] == '(' ) {
                st.push(i);
                rm[i]=true;
            }
            if (s[i] == ')') {
                if(!st.empty()) {
                    rm[st.top()]=false;
                    st.pop();
                }
                else {
                    rm[i]=true;
                }
            }
        }
        for(int i = 0 ; i < n ; ++ i ){
            if(!rm[i]) {
                ans+=s[i];
            }
        }
        return ans;
    }
};