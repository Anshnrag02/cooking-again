class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int target) {
        int l = 0, r=a.size()-1, mid;
        while(l<=r) {
            mid = l + (r-l)/2;
            if(a[mid][0]==target) return true;
            else if(a[mid][0]>target) r=mid-1;
            else l = mid+1;
        }
        mid = r;
        if (mid<0) return false;
        l=0, r=a[0].size()-1;
        int mid2;
        while(l<=r) {
            mid2 = l + (r-l)/2;
            if(a[mid][mid2]==target) return true;
            else if(a[mid][mid2]>target) r=mid2-1;
            else l = mid2+1;
        }


        return false;
    }
};
