class Solution {
public:
    void rotate(vector<int>& a, int k , int idx = 0) {
        if(k==0) return;
        int n = a.size();
        k = k%n;
        int temp = a[idx];
        if(idx+1 < k) rotate(a,k,idx+1);
        if(idx + k < n){rotate(a,k,idx+k);}
        a[(idx+k)%n]=temp;
    }
};