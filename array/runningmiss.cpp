class Solution {
public:
    void swap (int &a, int &b){
        a=a^b;
        b=a^b;
        a=a^b;
    }
    int missingNumber(vector<int>& a) {
        int n = a.size();
        for (int i = 0 ; i < n ; ++i) {
            if (a[i] == i){
                continue;
            }
            else {
                if (a[i]<n) {
                    swap(a[i],a[a[i]]);
                    --i;
                }
            }
        }
        for(int i = 0 ; i < n ; ++i){
            if(a[i]!=i) return i;
        }
        return n;
    }
};
