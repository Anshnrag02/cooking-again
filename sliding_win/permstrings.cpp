class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length()) return false;
        vector<int>a(26,0);
        vector<int>b(26,0);
        int i = 0;
        int m = s1.length();
        int n = s2.length();
        for(int i=0 ; i < m ; ++i){
            a[(s2[i])-'a']++;
            b[(s1[i])-'a']++;
        }
        
        if (a==b) return true;
        for(int i=1 ; i < n - m + 1 ; ++i){   
            a[(s2[i-1])-'a']--;
            a[(s2[i+m-1])-'a']++;
            if (a==b) return true;
        }    
        return false;
    }
};
