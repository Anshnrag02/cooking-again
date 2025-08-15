class Solution {
public:
    bool checkPowersOfThree(int n) {
        for (int i = 16; i>=0; --i){
            if(n>=pow(3,i)) {
                n-=pow(3,i);
            }
        }
        return n==0;
    }
};


// more optimal solution 
class Solution {
public:
    bool checkPowersOfThree(int n) {
        int k = pow(3,16);
        for (int i = 16; i>=0; --i){
            if(n>=k) {
                n-=k;
            }
            k/=3;
        }
        return n==0;
    }
};