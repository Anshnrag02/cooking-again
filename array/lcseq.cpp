class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s;
        for (int x:nums) s.insert(x);
        int ans = 0;
        for (int x: s) {
            if(s.find(x-1)==s.end()) {
                int count = 1;
                int j = x+1;
                while(s.find(j)!=s.end()){
                    ++j;
                    ++count;
                }
                ans = max(ans,count);
            }
        }
        return ans;
    }
};
