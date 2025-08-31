class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>mp(2010,0);
        for(int i = 0 ; i < n ; ++i){
            mp[nums[i]+1000]++;
        }
        n = 2010;
        priority_queue<pair<int,int>>pq;
        for(int i = 0 ; i < n; ++i) {
            if (mp[i]) pq.push({mp[i],i-1000});
        }
        vector<int>ans;
        while(k--){
            pair<int,int>p = pq.top();
            ans.push_back(p.second);
            pq.pop();
        }
        return ans;
    }
};
