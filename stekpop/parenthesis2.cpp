
class Solution {
public:
    bool canBeValid(string s, string locked) {
        stack<int> pushX;
        stack<int> pushA;
        int n = s.length();
        if(n%2==1) return false;
        for(int i = 0 ;  i < n ; ++i){
            if(locked[i] == '0'){
                pushX.push(i);
            }
            if(s[i]=='(' and locked[i] == '1'){
                pushA.push(i);
            }
            if(s[i]==')' and locked[i] == '1'){
                if(pushA.empty() and pushX.empty()) return false; //theres nothing we can do :'(
                if(!pushA.empty()) pushA.pop();
                else pushX.pop();
            }
        }
        while(!pushA.empty()){
            if(pushX.empty()) return false;
            if(pushA.top() > pushX.top()) return false;
            pushA.pop();
            pushX.pop();
        }

        return true;
    }
};