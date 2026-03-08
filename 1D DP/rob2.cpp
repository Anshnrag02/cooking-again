class Solution {
public:   
    int rob(vector<int>& a) {
        int n = a.size();
        if(n==1) return a[0];
        if(n==2) return max(a[0],a[1]);
        if(n==3) return max({a[0],a[1],a[2]});
        vector<int>dp1 = a;
        vector<int>dp2 = a;
        for(int i = 0 ; i < n-1; ++i){
            if(i>=2){
                dp1[i]+=dp1[i-2];
                dp1[i]=max(dp1[i],dp1[i-1]);

                dp2[i+1]+=dp2[i-1];
                dp2[i+1]=max(dp2[i+1],dp2[i]);
            }
            if(i==1){
                dp1[i]=max(dp1[i],dp1[i-1]);
                dp2[i+1]=max(dp2[i+1],dp2[i]);
            }
        }
        return max(dp1[n-2],dp2[n-1]);
    }
};

