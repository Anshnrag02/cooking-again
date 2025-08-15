// idea is to take and with previous ex 1000 & 0111 = 0

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n>0 && (n & (n-1))==0);
    }
};