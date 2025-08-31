// o(1) space solution

class Solution {
public:
    int trap(vector<int>& a) {
        int n = a.size();
        if(n<=2) return 0;
        int l = 0 ; 
        int r = n-1;
        int maxl = 0, maxr = 0;
        int curr = 1;
        int water = 0;
        while (l<r) {
            
            maxl = max(maxl, a[l]);
            maxr = max(maxr,a[r]);
            if(maxl<=maxr) {
                curr = ++l;
                water += max(maxl - a[curr], 0);
            }
            else {
                curr = --r;
                water += max(maxr - a[curr], 0);
            }
        }
        return water;
    }
};
