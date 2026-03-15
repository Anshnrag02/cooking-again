// Kahn Algo

class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int>ans;
        queue<int>q;
        vector<int>indegree(V,0);
        vector<vector<int>> adj(V);
        for(vector<int> v: edges){
            adj[v[0]].push_back(v[1]);
            ++indegree[v[1]];
        }
        for(int i = 0 ; i < V ; ++i){
            if(!indegree[i]) q.push(i);
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(int x: adj[node]){
                if(indegree[x]){
                    --indegree[x];
                    if(!indegree[x]){
                        q.push(x);
                    }
                }
            }
        }
        
        return ans;
        
    }
};