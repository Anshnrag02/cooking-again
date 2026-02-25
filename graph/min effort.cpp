class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        set<vector<int>>st;
        st.insert({0,0,0});
        int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        while(!st.empty()){
            vector<int> v = *(st.begin());
            st.erase(v);
            int x = v[1], y = v[2], e = v[0];
            if(x==n-1 and y==m-1) return e;
            for(auto tmp: dir){
                int nx = x+tmp[0], ny = y + tmp[1];
                
                if (nx < n and ny < m and nx >= 0 and ny >= 0){
                    int etemp = max(e,abs(a[nx][ny] -  a[x][y]));
                    if(etemp<dist[nx][ny]){
                    if(dist[nx][ny] != INT_MAX){
                        st.erase({dist[nx][ny],nx,ny});
                    }
                    st.insert({etemp , nx, ny});
                    dist[nx][ny]=etemp;}
                }
            }
        }
        return -1;
    }
};