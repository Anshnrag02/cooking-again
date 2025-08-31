class Solution {
public:
    bool containsDuplicate(vector<int>& a) {
        unordered_set<int>s;
        int n = a.size();
        for (int i = 0 ; i < n ; ++i) {
            if(s.find(a[i]) != s.end()) return true;
            s.insert(a[i]);
        }
        return false;
    }
};