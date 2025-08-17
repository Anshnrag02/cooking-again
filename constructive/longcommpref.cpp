class Solution {
public:
    string longestCommonPrefix(vector<string>& strs, int idx = 0) {
        char c='A';
        for(string s: strs) {
            if(idx >= s.length()) {
                return "";
            }
            else {
                if(c=='A'){
                    c=s[idx];
                }
                else if ((c) != s[idx]) {
                    return "";
                }

            }
        }
        if (c=='A') return "";
        return c + longestCommonPrefix(strs, idx+1);
    }
};