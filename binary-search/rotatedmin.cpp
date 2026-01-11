class Solution {
public:
    int findMin(vector<int> &a) {
        int l = 0 , r=a.size()-1;
        int ans = INT_MAX;
        while(l<=r) {
            int mid = l + (r-l)/2;
            if(a[mid]<a[r]) {
                r=mid-1;
            }
            else {
                l = mid+1;
            }
            ans = min(a[mid],ans);
        }
        return ans;
    }
};
