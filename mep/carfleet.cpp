class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& sp) {
        vector<float>tth(1000001,-1);
        int n = pos.size();
        for(int i = 0 ; i < n ; ++i) {
            tth[pos[i]] = (float)(target - pos[i]) / sp[i];
        }
        int ans = 0;
        float running = -1;
        for(int i = 1000000 ; i>=0 ; --i){
            if (tth[i]!=-1){
                if(running == -1 || tth[i]>running){
                    running=tth[i];
                    ++ans;
                }
            }
        }
        return ans;
    }
};
