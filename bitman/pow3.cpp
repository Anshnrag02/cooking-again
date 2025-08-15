// find the max power of 3 known to int then %n 3^k % 3^l = 0. for k>l 

class Solution {
public:
    bool isPowerOfThree(int n) {
        int base = pow(3,19);
        return n>0 && base%n==0;
    }
};