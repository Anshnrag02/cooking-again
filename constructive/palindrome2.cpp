class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& queries, int len) {
        vector<long long>v;
        int start = pow(10,((len+1)/2)-1);
        int range = 9*start;
        for (int q:queries) {
            if (q > range) v.push_back(-1);
            else {
                int fh= start + q - 1;
                string fhs = to_string(fh);
                string sh = "";
                for (int i =  fhs.length()-1-(len%2); i>=0; --i){
                    sh+=fhs[i];
                }
                string fs=fhs+sh;
                v.push_back(stoll(fs));
            }
        }
        return v;
    }
};