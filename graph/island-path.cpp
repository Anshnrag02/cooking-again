class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        int ans = 0 ;
        int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        for (int i = 0 ; i < n ; ++i) {
            for (int j = 0 ; j < m ; ++j) {
                if(a[i][j]==1){ 
                    queue<vector<int>>q;
                    int temp = 0;
                    q.push({i,j});
                    a[i][j]=0;
                    while(!q.empty()){
                        ++temp;
                        vector<int>v=q.front();
                        q.pop();
                        int x = v[0];
                        int y = v[1];         
                        for(int k = 0 ; k < 4; ++k){
                            int nx = x + dir[k][0];
                            int ny = y + dir[k][1];
                            if (nx< n and nx>=0 and ny<m and ny>=0 and a[nx][ny]==1){
                                q.push({nx,ny});
                                 a[nx][ny]=0;
                            }
                        }
                    }
                    ans = max(ans,temp);
                }
            }
        }
        return ans;
    }
};
