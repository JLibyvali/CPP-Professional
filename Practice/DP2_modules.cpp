#include <iostream>
#include <algorithm>
#include <string>


using namespace std;

// 1. max sub-sequence
const int inf = 0x7fffffff;

int main(){
	
	//1. the max sub-sequence in one sequence
//	int num[110],n;
//	cin>>n;
//	for(int i=0;i<n;i++){
//		cin>>num[i];
//	}
//	
//	int ans = -inf;
//	for(int i =0;i<n;i++){
//		ans = max(ans,num[i]);
//	}
//	if( ans <= 0){
//		cout << ans <<endl;
//	}else {
//		// DP
//		int sum=0;	// maintain one sum 
//		for(int i=0;i<n;i++){
//			if(sum + num[i] < 0){
//				sum = 0;
//			}else {
//				sum += num[i]; 
//			}
//			ans = max(ans,sum);	// catch the max 
//		}
//		
//		cout<<ans<<endl;
//	}
	
	
	//2. LIS: Longes incereasing subsequecne
//	int dp[110],ai[110],n;
//	cin>>n;
//	for(int i=0;i<n;i++){
//		cin>>ai[i];
//	}
//	
//	int ans =0;
//	for(int i=0;i<n;i++){
//		dp[i] = 1;
//		for(int j=1 ;j<i;j++){
//			if(ai[j]<ai[i]){
//				dp[i] = max(dp[i],dp[j]+1);
//			}
//		}
//		ans = max(ans,dp[i]);
//	}
//
//	cout<<ans<<endl;
	//3. the longest common sub-sequence
	int dp[110][110] { };
	string a,b;
	cin>>a>>b;
	int lena = a.size();
	int lenb = b.size();
	for(int i=1; i<=lena;i++){
		for(int j=1;j<=lenb;j++){
			if(a[i-1] == b[j-1]){
				dp[i][j] = dp[i-1][j-1] + 1;
			}else{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	
	cout<<dp[lena][lenb]<<endl;
	
	return 0;
} 
