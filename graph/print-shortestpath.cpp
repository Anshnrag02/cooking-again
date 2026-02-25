class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<vector<vector<int>>>adj(n);
        for(vector<int>edge: edges){
            int u = edge[0]-1;
            int v = edge[1]-1;
            int wt = edge[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        vector<int>dist(n,INT_MAX);
        vector<int>parent(n,-1);
        
        set<pair<int,int>>st;
        
        dist[0]=0;
        st.insert({0,0});
        
        while (!st.empty()){
            pair<int,int> it = *(st.begin());
            int u = it.second;
            st.erase(it);
            
            for(vector<int> x : adj[u]){
                int v = x[0];
                int wt = x[1];
                
                if(dist[u] + wt < dist[v]){
                    
                    if(dist[v] != INT_MAX){
                        st.erase({dist[v],v});
                    }
                    parent[v] = u;
                    dist[v] = dist[u]+wt;
                    st.insert({dist[v],v});
                }
            }
        }
        if (dist[n-1]!=INT_MAX){
            vector<int>ans;
            int x = n-1;
            while(x!=-1){
                ans.push_back(x+1);
                x=parent[x];
            }
            ans.push_back(dist[n-1]);
            reverse(ans.begin(),ans.end());
            return ans;
        }
        return {-1};
    }
};