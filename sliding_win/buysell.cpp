class Solution {
public:
    int maxProfit(vector<int>& a) {
    int n= a.size();
      int ans = 0; 
      int min_buy=a[0];
      for (int i = 0 ; i < n ; ++i){
        min_buy=min(a[i],min_buy);
        ans = max (ans, a[i] - min_buy);
      }
      return ans;  
    }
};
