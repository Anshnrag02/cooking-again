class Solution {
public:
    void swap (int & a ,int & b){
        a = a^b;
        b = a^b;
        a = a^b;
    }
    int findDuplicate(vector<int>& a) {
        int n = a.size();
        for(int i = 0 ; i < n ; ++i){
            if (i != a[i]-1){
                if(a[i] == a[a[i]-1]) return a[i];
                swap(a[i] , a[a[i]-1]);
                --i;
            }
        }
        return -1;
    }
};
