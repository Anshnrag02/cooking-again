class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& a) {
        
        int n = a.size();
         if (a[0][0] == 1 || a[n-1][n-1] == 1) return -1;
        vector<vector<int>> dir = {
            {1,0},
            {-1,0},
            {1,1},
            {1,-1},
            {-1,-1},
            {-1,1},
            {0,1},
            {0,-1}
        };
        int moves = 0;
        queue<vector<int>>q;
        q.push({0,0,1});
        a[0][0]=1;
        while(!q.empty()){
            vector<int> v = q.front();
            int x= v[0];
            int y= v[1];
            int mv = v[2];
            if(x== n-1 and y==n-1) return mv;
            q.pop();
            for (vector<int>tmp: dir){
                int i = tmp[0];
                int j = tmp[1];
                if(!(i==0 and j==0) and x+i>=0 and x+i<n and y+j>=0 and y+j<n and a[x+i][y+j]==0){
                    q.push({x+i,y+j,mv+1});
                    a[x+i][y+j]=1;
                }    
            }
        }
        return -1;
    }
};