class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int l = 0 , r=INT_MAX;
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int ans = INT_MAX;
        while(l<=r){
            int mid = l + (r-l)/2;
            int itr = 0;
            for(int x:heaters){
                while(itr<houses.size() and houses[itr]>=x-mid and houses[itr]<=x+mid) {
                    ++itr;
                }
            }
            if(itr<houses.size()) l = mid +1;
            else{ 
                ans=min(ans,mid);
                r = mid-1;
            }
        }
        return ans;
    }
};