class Solution {
    void dfs(int node, vector<vector<int>>&adj, vector<bool>&vis, stack<int>&st){
        for(int x: adj[node]){
            
            if (!vis[x]){
                vis[x]=1;
                dfs(x, adj, vis, st);
            }
        }
        st.push(node);
    }
  public:
    vector<int> topoSort(int V, vector<vector<int>>& a) {
        // code here
        stack<int>st;
        vector<int>ans;
        vector<vector<int>>adj(V);
        vector<bool>vis(V,0);
        for(auto x: a){
            adj[x[0]].push_back(x[1]);
        }
        for(int i = 0; i<V ; ++i){
            if(!vis[i]) {
                vis[i]=1;
                dfs(i, adj, vis, st);
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());st.pop();
        }
        return ans;
    }
};