class Solution {
public:
    int n=0,m=0;
    int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    void dfs(int x, int y, vector<vector<char>>& a, vector<vector<bool>>& noop){
        noop[x][y]=1;
        for(int i = 0 ; i < 4; ++i){
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if(nx<n and ny <m and nx>=0 and ny>=0 and a[nx][ny]=='O' and !noop[nx][ny]){
                dfs(nx,ny,a,noop);
            }
        }
    }

    void solve(vector<vector<char>>& a) {
        n = a.size();
        m = a[0].size();
        vector<vector<bool>>noop(n, vector<bool>(m,0));
        for(int i = 0 ; i < n ; ++i){
            if (!noop[i][0] and a[i][0]=='O'){
                dfs(i,0,a,noop);
            }
            if (!noop[i][m-1] and a[i][m-1]=='O'){
                dfs(i,m-1,a,noop);
            }
        }
        for(int i = 0 ; i < m ; ++i){
            if (!noop[0][i] and a[0][i]=='O'){
                dfs(0,i,a,noop);
            }
            if (!noop[n-1][i] and a[n-1][i]=='O'){
                dfs(n-1,i,a,noop);
            }
        }

        for(int i = 1 ; i < n-1 ; ++i){
            for(int j = 1 ; j < m-1 ; ++j){
                if(a[i][j]=='O' and !noop[i][j]) a[i][j]='X';
            }
        }
    }
};
