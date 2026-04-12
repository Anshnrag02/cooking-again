class Solution {
public:
    int dp[5002][302];
    vector<int>a;

    int f(int x,int idx){
        if(x==0) return dp[x][idx]=1;
        if(idx==a.size()) return dp[x][idx]=0;
        if (dp[x][idx]==-1) {
            dp[x][idx]=0;
            if(a[idx]<=x){
                dp[x][idx]+=f(x-a[idx],idx);
            }
            dp[x][idx]+=f(x,idx+1);
        }
        return dp[x][idx];
    }

    int change(int amount, vector<int>& coins) {
        for(int i = 0 ; i < 5002 ; ++i){
            for(int j=0; j < 302; ++j){
                dp[i][j]=-1;
            }
        }

        a=coins;

        return f(amount,0);

    }
};
