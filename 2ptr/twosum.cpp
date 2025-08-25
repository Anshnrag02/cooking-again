class Solution {
public:
    vector<int> twoSum(vector<int>& a, int target) {
        int s = 0 ; 
        int e = a.size()-1;

        while(s<e) {
            if (a[s] + a[e] > target) {
                --e;
            }
            else if (a[s]+a[e]<target) {
                ++s;
            }
            else {
                return {s+1,e+1};
            }
        }

        return {-1,-1};

    }
};
