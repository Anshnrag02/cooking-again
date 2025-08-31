class Solution {
public:
    bool isAnagram(string s, string t) {
      vector<int>mp (26 , 0);
      int n=s.length();
      int m=t.length();
      for(int i = 0 ; i < n ; ++i){
        mp[int(s[i]-'a')]++;
      }
      for(int i = 0 ; i < m ; ++i){
        mp[int(t[i]-'a')]--;
      }
    for (auto x: mp) {
        if (x!=0) return false;
    }
      return true;
    }
};
