class Solution {
public:

    int dp[1001];

    int f(int index, vector<int>&a){
        if(index==a.size()) return dp[index]=0;

        if(dp[index]==-1){
            int temp = 1;
            for(int i = index+1; i<a.size(); ++i){
                if(a[i]>a[index]) {
                    temp=max(temp,1+f(i,a));
                }
            }
            dp[index]=temp;
        }
        return dp[index];

    }

    int lengthOfLIS(vector<int>& a) {
        for(int i = 0 ; i < 1001 ; ++i){
            dp[i]=-1;
        }
        int n = a.size();
        int ans = 1;
        for(int i = 0 ; i < n ; ++i){
            ans = max(ans,f(i,a));
        }
        return ans;
    }
};
