class Solution {
  public:
    int countWays(int n, int k) {
        // code here
        vector<int> ans(n,0);
        ans[0]=k;
        ans[1]= k*(k);
        for(int i = 2 ; i < n ; ++i){
            ans[i]=(ans[i-2]+ans[i-1])*(k-1) ;
        }
        return ans[n-1];
    }
};

