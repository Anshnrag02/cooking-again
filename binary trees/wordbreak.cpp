class Solution {
public:
    int dp[201];
    bool startsWith(string a, string b, int offset){
        for(int i = 0 ; i < b.length(); ++i){
            if(a[i+offset]!=b[i]) return false;
        }
        return true;
    }

    bool f(string s, vector<string>& a, int offset=0) {

        if(offset==s.length()) return dp[offset]=1;
        if(dp[offset]==-1){
            dp[offset]=0;
            for(string word: a){
                if(s.length()-offset>=word.length() && startsWith(s,word,offset)){
                    dp[offset]=dp[offset] + f(s,a,offset+word.length());
                    if(dp[offset]) break;
                }
            }
        }
        return dp[offset];
    }

    bool wordBreak(string s, vector<string>& a) {
        for(int &x: dp){
            x=-1;
        }
        return f(s,a);
    }
};
