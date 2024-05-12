//
// Created by jlibyvali on 24-4-8.
//
#include<bits/stdc++.h>

using namespace std;
using ll = long long;
#define endl "\n"

// ############# Binary
// Thought:
/*Use the bit '0' or '1' to represent status
 * Always use the operator: &, |, >>, <<.
 * 1.If wanna judge one bit is '0' or '1'? Use the '(i & (1<<j)), j>=0'
 * 2.If wanna traverse all status, use ranges: 0 < i < (1<<n): (1<<n) = 2^n -1, totally 'n-th' 1.
 *
 * */

void LiBai() {
/* LiBai's alcohol meet store double it, meet flower reduce one.
 *  In a road, he totally meets store 5 times, flowers 10 times, the last meet was flower and alcohol is remained 1.
 *  calculate the result that meeting store and flower order num.
 * */
    int ans = 0;
    for (int i = 0; i < (1 << 14); i++) {   // traverse all status like:"110101001010..."
        int alcohol = 2;
        int flower = 0;
        int store = 0;

        for (int j = 0; j < 14; j++) {

            if (i & (1 << j)) {
                store++;
                alcohol *= 2;
            } else {
                flower++;
                alcohol -= 1;
            }
        }

        if (alcohol == 1 && store == 5 && flower == 9) {
            ans += 1;
        }
    }

    cout << "LiBai: " << ans << endl;
}


/* 'n' number, result X, from the n number choose any numbers plused equal with X.
 * calculate result num;
 * */

void Cal() {

    int n = 6, X = 6, ans = 0;
    int a[100] = {1,2,3,4,5,6};

    // O(2^n * n)
    for(int i=0; i< (1<<n);i++){    // traverse equal with: i < 2 ^n;
        int num = 0;

        for(int j=0;j<n;j++){
            if(i & (1<<j)){
                num += a[j];
            }
        }

        if(num == X){
            ans += 1;
        }

    }

    cout<<"Cal: "<<ans<<endl;
}

/*When elements' num is small.
 *We can use dp[1<<n] ( dp[2^n] ) represent that status like:"01010101..."
 * */

/* n people play passing object, at beginning the Obj in anyone hand, he can pass it to next one
 * calculate the min cost passing object after it passing all person.
 * */

int dp[1<<16][20]; // n<20

void scDP(){
    int n = 3;
    int a[20][20] = {{-1,2,4},{3,-1,5},{4,4,-1}};
    // dp[1<<i][j], i: haven passed person, j: the last person. If 'j' used, add it using "i | 1<<j".
    // the equation: dp[i | 1<<k][k] = min(dp[i | 1 <<k][k], dp[i][j] + dist[j][k] ).
    memset(dp,0x3f,sizeof(dp));

    for(int i=0; i<n;i++){
        dp[1<<i][i] = 0;    // anyone can be strat
    }

    for(int i=0;i<(1<<n);i++){
        for(int j=0;j <n;j++){

            if(i & (1<<j)){
                for(int k=0;k<n;k++){

                    if(!(i & (1<<k)) ) {
                        dp[i | 1 << k][k] = min(dp[i | 1 << k][k], dp[i][j] + a[j][k]);
                    }

                }

            }

        }
    }

    int ans = 0x3f3f3f3f;
    for(int i=0;i<n;i++){
        ans = min(ans,dp[(1<<n) - 1][i]);   // the object could at anyone
    }

    cout<<"scDP: "<<ans;

}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    cout << "#################Binary basic##############################" << endl;
    LiBai();
    Cal();
    cout << "################Status Compression Algorithm##################" << endl;
    scDP();


    return 0;
}
