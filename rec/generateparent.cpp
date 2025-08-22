class Solution {
public:
    vector<string>ans;
    
    void rec(int n, int m, string s) {
        if(n==0 and m==0) ans.push_back(s);
        
        if (n > m ) return;

        if(n){
            rec(n-1,m,s + '(');
        }

        if (m){
            rec(n,m-1,s+')');
        }

    }

    vector<string> generateParenthesis(int n) {
        rec(n,n,"");
        return ans;
    }
};