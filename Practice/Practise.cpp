#include <bits/stdc++.h>
using namespace std;


int main() {

  vector<int> vec;
    int n;
    cin>>n;
    while(n--){
        int tmp;
        cin>>tmp;
        vec.push_back(tmp);
    }

    sort(vec.begin(),vec.end(),greater);
    for(const auto& ele : vec){
        cout<<ele<<" ";
    }

  return 0;
}