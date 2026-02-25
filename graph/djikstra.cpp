class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<vector<int>>>adj(V);
        for(vector<int>x: edges){
            adj[x[0]].push_back({x[1],x[2]});
            adj[x[1]].push_back({x[0],x[2]});
        }
        vector<int>dist(V,INT_MAX);
        set<pair<int,int>>st;
        dist[src] = 0;
        st.insert({0,src});
    
        while(!st.empty()){
            auto it = *(st.begin());
            int node = it.second;
            st.erase(it);
            for(vector<int> v: adj[node]){
                int next_node = v[0];
                int wt = v[1];
                if(dist[node]+wt < dist[next_node]){
                    if(dist[next_node] < INT_MAX){
                        st.erase({dist[next_node],next_node});
                    }
                    dist[next_node] = dist[node]+wt;
                    st.insert({dist[next_node],next_node});
                }
            }
        }
        return dist;
    }
};