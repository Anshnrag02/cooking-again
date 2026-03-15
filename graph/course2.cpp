class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& a) {
        // code here
        vector<int>ans;
        queue<int>q;
        vector<int>indegree(V,0);
        vector<vector<int>> adj(V);
        for(vector<int> v: a){
            adj[v[1]].push_back(v[0]);
            ++indegree[v[0]];
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

        if(ans.size() < V) return {};
        
        return ans;
    }
};
