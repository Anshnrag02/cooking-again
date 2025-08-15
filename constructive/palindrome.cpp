class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0) return false;
        long int rev = 0; 
        int temp = x;
        while (temp>0) {
            rev+=temp%10;
            temp/=10;
            if(temp>0) rev*=10;
        }
        return rev == x;
    }
};