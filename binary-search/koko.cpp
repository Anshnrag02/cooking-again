class Solution {
public:
    int minEatingSpeed(vector<int>& a, int h) {
        int r=INT_MAX, l = 1;
        while(l<=r){
            int mid = l + (r-l)/2;
            int t=0;
            for(int x:a){
                t+=x/mid;
                if(x%mid)
                    t++;
            }

            if(t>h){
                l=mid+1;
            }
            else {
                r=mid-1;
            }
        }
        return l;
    }
};