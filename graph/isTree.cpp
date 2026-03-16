class Solution {
public:

    bool flag=0;

    void dfs(int node, int par, vector<vector<int>>& adj, vector<bool>& vis){
        if(flag) return;
        for(int x: adj[node]){
            
            if(x!=par){
                if (!vis[x]){
                    vis[x]=1;
                    dfs(x,node,adj,vis);
                }
                else{
                    flag=1;
                    return;
                }
            }
        }
        
    }

    bool validTree(int n, vector<vector<int>>& a) {
        vector<bool>vis(n);
        vector<vector<int>>adj(n);
        for(vector<int>x:a){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vis[0]=1;
        dfs(0, -1, adj, vis);
        if(flag) return false;
        for(auto x: vis) if(!x) return false;
        return true;
    }
};
