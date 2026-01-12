class Solution {
public:
    // 0 2 5 6 8 12 15
    // 
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        vector<int>a(n+1,0);
        for (int i = 1 ; i <=n ; ++i ) a[i] = a[i-1]+nums[i-1];
        int l = 0 , r = 0;
        while(r<=n) {
            if(a[r]-a[l] < target) {
                ++r;
            }
            else {
                ans=min(ans,r-l);
                ++l;
            }
        }
        if(ans == INT_MAX) return 0;
        return ans;
    }
};