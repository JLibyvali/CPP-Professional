//
// Created by jlibyvali on 24-4-8.
//
#include<bits/stdc++.h>
using namespace std;
using ll = long long ;
#define endl "\n"

int N,K;
vector<ll> v(1e5 + 10);

int check(int mid){
    int ans = 0;
    for(int i=0;i<N;i++){
        ans += v[i] / mid;
    }
    return ans;
}


int main(){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    cin>>N>>K;
    for(int i=0;i<N;i++){
        cin>>v[i];
    }

    int l=0, r= 1e9 + 10,res = -0x3f3f3f3f;
    bool f =false;

    while(l + 1 != r ){
        int mid = (l+r) / 2;
        int tmp = check(mid);

        if(tmp>= K){
            l = mid;
        }else{
            r = mid;
        }

    }

    if(l > 0){
        cout<<l;
    }else{
        cout<<"-1";
    }



    return 0;
}
