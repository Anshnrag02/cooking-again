
class Solution {
public:
    int n=0;
    int dp[1002];
    int f(string s, int idx){
        if(idx == n) return dp[idx]=1;
        if(s[idx]=='0') return dp[idx]=0;
        if(dp[idx]==-1) {
            int ans=0;
            if((s[idx]=='1' and idx+1 < n)or(s[idx]=='2' and idx+1 < n and s[idx+1] <= '6')) {
                ans+=f(s,idx+2);
            }
            dp[idx]=ans+f(s,idx+1);
        }
        return dp[idx];
    }

    int numDecodings(string s) {
        n = s.length();
        for(int i = 0 ; i <= n ; ++i){
            dp[i]=-1;
        }
        return f(s,0);
    }
};
