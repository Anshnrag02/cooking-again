class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<bool>a(1001,0);
        vector<bool>b(1001,0);
        vector<int>ans;
        for (int x: nums1) a[x]=true;
        for (int x: nums2) b[x]=a[x];
        for ( int i = 0 ; i <=1000 ; ++i) if(b[i])ans.push_back(i);
        return ans;
    }
};