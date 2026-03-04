class Solution {
public:
    int dp[1002][1002];
    int n , m;
    string a, b;
    // c a 
    // c r a b 

    int f(int x, int y){
        if (x==0 || y==0) return dp[x][y]=0;
        if (dp[x][y]==-1){
            dp[x][y]= (a[x-1]== b[y-1])? 1 + f(x-1,y-1) : max(f(x,y-1) , f(x-1,y)) ;
        }
        return dp[x][y];
    }

    int longestCommonSubsequence(string text1, string text2) {
        a = text1;
        b=text2;
        n = a.length();
        m = b.length();
        for (int i = 0 ; i < 1002 ; ++i){
            for (int j = 0 ; j < 1002 ; ++j){
                dp[i][j]=-1;
            }
        }
        return f(n,m);
    }
};

class Solution {
public:
    int longestCommonSubsequence(string &a, string &b) {
    short m[2][1001] = {};
    for (auto i = 0; i < a.size(); ++i)
        for (auto j = 0; j < b.size(); ++j)
            m[!(i%2)][j + 1] = a[i] == b[j] ? m[i%2][j] + 1 : max(m[!(i%2)][j], m[i%2][j + 1]);
    return m[a.size()%2][b.size()];
}
};