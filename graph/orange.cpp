class Solution {
public:
    int orangesRotting(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        int ans = 0;
        int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        queue<vector<int>>q;
        for (int i = 0 ; i < n ; ++i) {
            for (int j = 0 ; j < m ; ++j) {
                if(a[i][j]==2){
                    q.push({i,j,0});
                }
            }
        }
        while(!q.empty()){
            vector<int>v=q.front();
            q.pop();
            int x = v[0];
            int y = v[1];   
            int t = v[2]; 
            ans = max(t,ans);  
            for(int k = 0 ; k < 4; ++k){
                int nx = x + dir[k][0];
                int ny = y + dir[k][1];
                if (nx< n and nx>=0 and ny<m and ny>=0 and a[nx][ny]==1){
                    q.push({nx,ny,t+1});
                    a[nx][ny]=2;
                }
            }
        }

        for (int i = 0 ; i < n ; ++i) {
            for (int j = 0 ; j < m ; ++j) {
                if(a[i][j]==1){
                    return -1;
                }
            }
        }

        return ans;
    }
};
