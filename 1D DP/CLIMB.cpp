class Solution {
public:
    int climbStairs(int n) {
        if(n<=2) return n;
        int s0=1;
        int s1=2;
        int ans=0;
        for(int i = 3; i<=n; ++i){
            ans = s0 + s1;
            s0 = s1;
            s1 = ans; 
        }
        return ans;
    }
};
