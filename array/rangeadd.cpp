/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;cin>>n;
    vector<int>v(n,0);
    int m; cin>>m;
    int a,b,c;
    for(int i = 0 ; i < m ; ++i){
        cin>>a>>b>>c;
        v[a]=c;
        if(b<n-1) v[b+1]=-c;
    }
    for(int i = 0 ; i < n ; ++i){
        if(i>0) v[i] = v[i]+v[i-1];
        cout<<v[i]<<" ";
    }
    return 0;
}