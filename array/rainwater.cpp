class Solution {
public:
    int trap(vector<int>& a) {
        int n = a.size();
        vector<int> l(n,0);
        vector<int> r(n,0);
        for (int i = 1 ; i < n  ; ++i){
            l[i] = max(l[i-1], a[i-1]);
        }
        for (int i=n-2 ; i>=0; --i) {
            r[i] =max(r[i+1], a[i+1]);
        }

        int w =0;
        for (int i = 0; i<n ;++i) {
            int temp=min(l[i],r[i]);
            if (a[i]<temp) w+=temp-a[i];
        }
        return w;
    }
};
