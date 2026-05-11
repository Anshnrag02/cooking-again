class Solution {
public:
    int c2i (char x){
        if(x>='a'){
            return 26 + x-'a';
        }
        return x - 'A';
    }

    bool isValid (vector<int>c){
        for(auto x:c){
            if(x>0) return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        vector<int>mp(52,0);
        vector<int>q;
        for(auto x:t){
            mp[c2i(x)]++;
        }
        for(int i = 0 ; i < s.length(); ++i){
            if(mp[c2i(s[i])]){
                q.push_back(i);        
            }
        }
        int ans_l=0,ans_r=s.length();
        int l = 0, r=0;
        while(l<=r and r<q.size()){
            mp[c2i(s[q[r]])]--;
            if(isValid(mp)){
                if((q[r]-q[l]) < (ans_r - ans_l)){
                    ans_l = q[l];
                    ans_r = q[r];
                }
                ++mp[c2i(s[q[l]])];
                ++mp[c2i(s[q[r]])];
                ++l;
            }
            else{
                ++r;
            }
        }
        if(ans_r==s.length()) return "";
        string ans="";
        for(int i = ans_l ; i<=ans_r; ++i){
            ans+=s[i];
        }
        return ans;
    }
};
