class Solution {
public:
    int maxArea(vector<int>& a) {
        int s = 0;
        int e = a.size() - 1;
        int maxAr=0;
        while (s<e) {
            int area = (e-s) * min(a[s], a[e]);
            maxAr = max (area, maxAr);
            if(a[s]<a[e]){
                s++;
            }
            else {
                e--;
            }
        }
        return maxAr;
    }
};
