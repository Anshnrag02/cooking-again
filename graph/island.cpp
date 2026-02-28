class Solution {
public:

    int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    int n=0,m=0;
    void consumeIsland(int x,int y, vector<vector<char>>& a){
        a[x][y]=0;
        for(int i = 0 ; i < 4; ++i){
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if (nx< n and nx>=0 and ny<m and ny>=0 and a[nx][ny]=='1'){
                consumeIsland(nx,ny,a);
            }
        }
    }

    int numIslands(vector<vector<char>>& a) {
        n = a.size();
        m = a[0].size();
        int ans= 0;
        
        for(int i = 0 ; i < n ; ++i){
            for(int j = 0; j < m ; ++j){
                if(a[i][j]=='1') {
                    ans++;
                    consumeIsland(i, j , a);
                }
            }
        }
        return ans;
    }
};
