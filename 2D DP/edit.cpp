class Solution {
public:
    int dp[101][101];
    string a,b;

    int f(int i, int j){
        if(i == a.size()){
            return dp[i][j] = b.size() - j;
        }
        if(j == b.size()){
            return dp[i][j] = a.size() - i;
        }
        if(dp[i][j]==-1){
            dp[i][j]=0;
            if(a[i]==b[j]){
                dp[i][j]=f(i+1,j+1);
            }
            else{
                dp[i][j]=1 + min({f(i+1,j+1),f(i,j+1),f(i+1,j)});
            }
        }
        return dp[i][j];
    }

    int minDistance(string w1, string w2) {
        for(int i = 0 ; i <101 ; ++i){
            for(int j=0; j < 101 ; ++j){
                dp[i][j]=-1;
            }
        }
        a=w1;
        b=w2;
        return f(0,0);
    }
};
