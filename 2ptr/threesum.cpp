class Solution {
public:

    vector<vector<int>>ans;

    vector<vector<int>> threeSum(vector<int>& a) {
        sort(a.begin(), a.end());
        int n = a.size();
        for(int i = 0 ; i < n - 2; ++i) {
            int s = i+1 , e = n-1;
            while (s<e) {
                if(a[i] + a[s] + a[e] == 0) {
                    vector<int>temp = {a[i],a[s],a[e]};
                    if (ans.size() == 0 or (ans.size() and ans[ans.size()-1] != temp)) {ans.push_back({a[i],a[s],a[e]});}
                    s++;
                    e--;
                }
                else if(a[i] + a[s] + a[e] > 0) {
                    e--;
                }
                else {
                    s++;
                }
            }
            if(a[i+1]==a[i]) ++i;
        }
        return ans;
    }
};
