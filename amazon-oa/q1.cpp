#include<bits/stdc++.h>
using namespace std;

int main () {
    string s;
    cin>>s;

    int n = s.length();
    deque<char> dq;
    bool rev=false;
    for (int i = 0 ; i < n ; ++i ) {
        if(rev) {
            dq.push_front(s[i]);
        } else {
            dq.push_back(s[i]);
        }

        if (i%2) {
            rev=!rev;
        }
    }
    string res="";
    for (char c:dq) {
        res+=c;
    }
    if (n%2) {
        reverse(res.begin(),res.end());
    }
    cout<<res;
}