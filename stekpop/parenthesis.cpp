class Solution {
public:
    bool isValid(string brace) {
        stack<char> s;
        for (char k:brace) {
            if(k == '[' or k == '(' or k == '{' ) s.push(k);
            else if(k == ']' and !s.empty() and s.top()=='[' ) s.pop(); 
            else if(k == ')' and !s.empty() and s.top()=='(' ) s.pop();
            else if(k == '}' and !s.empty() and s.top()=='{' ) s.pop();
            else return false;
        }
        return s.empty();
    }
};