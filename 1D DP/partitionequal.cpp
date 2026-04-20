class Solution {

public:

    vector<int>a;
    bool ans=false;
    int tgt;

    void f(int idx , int sumSoFar, vector<vector<bool>>&vis) {
        if(vis[idx][sumSoFar]){
            return;
        }
        vis[idx][sumSoFar]=1;
        if(idx == a.size() and sumSoFar == tgt){
            ans = true;
        }
        
        if(idx < a.size()){
            f(idx+1,sumSoFar,vis);
            if(sumSoFar + a[idx] <= tgt) {
                f(idx+1, sumSoFar+a[idx],vis);
            }
        }
    }

    bool canPartition(vector<int>& ni) {
        a=ni;
        int sum=0;
        for(int x:a){
            sum+=x;
        }
        if(sum %2 != 0) return false;
        sum = sum/2;
        tgt = sum;
        vector<vector<bool>>vis(a.size()+1,vector<bool>(tgt+1,false));
        f(0,0,vis);
        return ans;
    }
};
