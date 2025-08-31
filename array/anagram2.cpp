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
    vector<vector<string>> s;
    vector<vector<string>> groupAnagrams(vector<string>& a) {
        int n = a.size();
        vector<bool>v(n,0);
        for (int i = 0 ; i < n ; ++i){
            if(v[i]== true) continue;
            vector<string>temp;
            temp.push_back(a[i]);
            for(int j = i+1 ; j<n ; ++j){
                if(!v[j] and isAnagram(a[i],a[j])) {
                    v[j]=true;
                    temp.push_back(a[j]);
                }
            }
            s.push_back(temp);

        }
        return s;
    }
};
