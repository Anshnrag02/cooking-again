class Solution {
public:
    int lengthOfLongestSubstring(string a) {
        int n = a.length();
        if (n==0) return 0;
        vector<int>pp(270,-1);
        int ans = 1;
        int l = 0 , r = 0 ;
        while( r<n ){
            if(pp[a[r]] <= r && pp[a[r]] >=l )
            {
                l=pp[a[r]]+1;
            }
            ans =max(ans, r-l +1);  
            pp[a[r]]=r;
            r++;
        }
        return ans;
    }
};
