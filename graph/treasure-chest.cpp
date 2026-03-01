class Solution {
public:
    long long INF = 2147483647;
    void islandsAndTreasure(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
        queue<pair<int,int>>q;
        for(int i = 0; i < n ; ++i){
            for(int j = 0 ; j < m ; ++j){
                if(a[i][j]==0) q.push({i,j});
            }
        }
        while(!q.empty()){
            pair<int,int>v=q.front();
            q.pop();
            int x = v.first;
            int y = v.second;
            for(int i = 0 ; i < 4 ; ++i){
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];
                if(nx<n and ny<m and nx>=0 and ny>=0 and a[nx][ny]==INF){
                    a[nx][ny]=a[x][y]+1;
                    q.push({nx,ny});
                }
            }
        }
    }
};
