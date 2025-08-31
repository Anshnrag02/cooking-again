class Solution {
public:
    vector<int> productExceptSelf(vector<int>& a) {
        int n = a.size();
        vector<int>ans(n,1);
        for (int i = 1 ; i<n; ++i){
            ans[i] = ans[i-1]*a[i-1];
        }
        int cp =1;
        for (int i = n-2; i>=0; --i){
            cp *=a[i+1];
            ans[i] = ans[i] *cp;
        }
        return ans;
    }
};
