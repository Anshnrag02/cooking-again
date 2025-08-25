class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        int st= 0 , en = n-1;
        while (st <= en) {
            cout<<en<<" "<<st<<"\n";
            if (!(s[st]>='a' and s[st]<='z') and !(s[st]>='A' and s[st]<='Z') and !(s[st]<='9' and s[st]>='0')) {
                st++;
                cout<<"k\n";
                continue;
            }
            if (!(s[en]>='a' and s[en]<='z') and !(s[en]>='A' and s[en]<='Z') and !(s[en]<='9' and s[en]>='0')) {
                en--;
                cout<<"l\n";
                continue;
            }
            if (tolower(s[en]) == tolower(s[st])) {
                st++,en--;
                continue;
            }
            return false;
        }
        return true;
    }
};
