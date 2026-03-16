class Solution {

    void dfs(int node, vector<vector<int>>& adj, vector<bool>&vis){
        for(int x: adj[node]){
            if(!vis[x]){
                vis[x]=1;
                dfs(x,adj,vis);
            }
        }
    }

public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<bool>vis(n,0);
        vector<vector<int>>adj(n);
        for(vector<int> x: edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        int ans = 0;
        for(int i = 0 ; i < n ; ++i){
            if(!vis[i]){
                ++ans;
                vis[i]=1;
                dfs(i,adj,vis);
            }
        }
        return ans;
    }
};
