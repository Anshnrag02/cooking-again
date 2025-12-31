class Solution {
public:
    int characterReplacement(string s, int k) {
        if(s.length()==1) return 1;

        int n = s.length();
        int ans = 1;
        
        for(char i='A'; i<='Z'; ++i) {
            int l = 0 , r = 0;
            int tol = 0;
            while(r<n) {
                if(s[r]==i)
                    ++r;
                else if (tol<k)
                    ++r,++tol;
                else if(s[l]==i)
                    ++l;
                else
                    ++l,--tol;
                
                ans = max(ans,r-l);
            }
        }
        return ans;
    }
};