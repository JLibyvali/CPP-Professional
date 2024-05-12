//
// Created by jlibyvali on 24-4-7.
//
#include<bits/stdc++.h>

using namespace std;

bool dp[110][110];

int palidrome(string s) {
    int ans = 0;
    for (int i = s.length() - 1; i >= 0; i--) {
        for (int j = i; j < s.length(); j++) {
            if (s[j] == s[i]) {

                if (j - i <= 1) {
                    ans += 1;
                    dp[i][j] = true;
                }
                if (dp[i + 1][j - 1]) {
                    ans += 1;
                    dp[i][j] = true;
                }
            }

        }
    }

    return ans;
}

int palidromeLen(string s){
    int dp[110][110];   // dp: between [i,j] palidrome string length
    int res = 0;
    int len  =s.length();

    for(int i=0;i<len;i++){
        dp[i][i] == 1;
    }

    for(int i=len-1;i>=0;i--){
        for(int j=i;j<len;j++){

            if(s[i] == s[j]){
                dp[i][j] = dp[i+1][j-1] + 2;
            }else{
                dp[i][j] = max(dp[i][j-1],dp[i+1][j]);
            }

        }
    }

    return dp[0][len-1];

}
int main() {

    string s;
    cin >> s;

    cout << "Palidrome num :" << palidrome(s) << endl;
    cin>>s;
    cout<<"Palidrome substring max: "<<palidromeLen(s)<<endl;


    return 0;
}