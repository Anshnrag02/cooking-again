class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        vector<vector<bool>>wet1(n,vector<bool>(m,0));
        vector<vector<bool>>wet2(n,vector<bool>(m,0));
        vector<vector<bool>>vis1(n,vector<bool>(m,0));
        vector<vector<bool>>vis2(n,vector<bool>(m,0));
        queue<vector<int>>q;
        vector<vector<int>>ans;
        int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        for(int i = 0 ; i < n ; ++i){
            q.push({i,0,1});
            q.push({i,m-1,2});
        }
        for (int i = 0 ; i < m ;  ++i){
            q.push({0,i,1});
            q.push({n-1,i,2});
        }

        while(!q.empty()){
            vector<int>v = q.front();
            q.pop();
            int x = v[0];
            int y = v[1];
            int ocean = v[2];
            if(ocean==1){
                wet1[x][y]=1;
                vis1[x][y]=1;
            }
            else{
                wet2[x][y]=1;
                vis2[x][y]=1;
            }
            for (int i = 0 ; i < 4 ; ++i){
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];
                if (nx < n and ny < m and nx>=0 and ny>=0){
                    if((ocean==1 and !vis1[nx][ny]) or (ocean==2 and !vis2[nx][ny])){    
                        if(a[x][y]<=a[nx][ny]){
                            q.push({nx,ny,ocean});
                        }   
                    }
                }
            }  
        }
        
        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < m ; ++j){
                if(wet1[i][j] and wet2[i][j]){
                    ans.push_back({i,j});
                }
            }
        }

        return ans;

    }
};
