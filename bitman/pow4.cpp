// make a crazy ass 10101010101010101....01 mask 

class Solution {
public:
    bool isPowerOfFour(int n) {
        int mask = 0;
        int maxpow = 16;
        for(int i = 0 ; i< maxpow ; ++i) {
            mask+=pow(4,i);
        }
        return n>0 && ((mask & n) == n) && ((n & n-1) == 0);
    }
};