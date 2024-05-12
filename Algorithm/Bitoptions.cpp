//
// Created by jlibyvali on 24-4-7.
//
#include<bits/stdc++.h>
using namespace  std;
using ll = long long ;

void check(ll n,string& ans){

    int  sr=0,en=31;
    while (sr < en && ((n >> sr)&1) == 0){
        sr++;
    }
    while(sr < en && ((n >> en)&1) == 0){
        en--;
    }
    for(int i=en;i>=sr;i--){
        ans +=  ( (n >> i)&1 ) + '0';    // from high to low bit
    }
}
int main() {

    ios::sync_with_stdio,cin.tie(0),cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        ll a,b;
        string s1,s2;

        cin>>a>>b;
        check(a,s1);
        check(b,s2);

        if(s1.find(s2) != string::npos ){   // if a can turn to b
            cout<<"Yes"<<'\n';
        }else{
            cout<<"No"<<'\n';
        }
    }

    return 0;
}
