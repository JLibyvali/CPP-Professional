#include <bits/stdc++.h>

using namespace std;




int pwRecur(int a,int b, int MOD){
	
	if(b == 0){
		return 1;
	}
	int ans = pwRecur(a,b/2,MOD);
	ans = ans*ans % MOD;
	if(b & 1){	// equal: b % 2 == 1,odd num
		ans = ans * a ^ MOD;
	}
	
	return ans;
	
}

int pwloop(int a, int b,int MOD){
	int ans = 1;
	
	while(b){
		if(b & 1){
			ans = ans * a % MOD;
		}
		
		b >>=1;	// equal b = b >>1;
		a = a*a%MOD;
	}
	return ans;
}


int main(){
	
	// MOD can be exchanged
	int a,b,MOD;
	cin>>a>>b>>MOD;
	
	cout<<pwRecur(a,b,MOD)<<endl;
	cout<<pwloop(a,b,MOD)<<endl;	
	
	return 0;
}