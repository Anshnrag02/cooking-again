class Solution {
public:


    int f(int x, vector<int>& coins, vector<int>&dp){
        if(x==0) return dp[x]=0;
        if(dp[x]==-1){
            dp[x]=INT_MAX;
            for(int coin: coins){
                if(coin<=x){
                    int temp = f(x-coin,coins,dp);
                    if(temp!=INT_MAX) ++temp;
                    dp[x]=min({temp,dp[x]});
                }
            }
        }
        return dp[x];
    }

    int coinChange(vector<int>& coins, int amount) {
        if(!amount) return 0;


        vector<int>dp(10001,-1);
        int ans = f(amount, coins, dp);

        if(ans==INT_MAX) return -1;
        return ans;

    }
};
