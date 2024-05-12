#include <iostream>


using namespace std;

/* Dynamic Planning

The core is: derive the recursive formula.
such like: Fibonaci sequence f[i] = f[i-1] + f[i-2]

*/



int main() {
// Fibonaci sequence
//using ll =  long long;
//const int N = 1e3;
//ll f[N];
// Fibonaci sequence
//	int n;
//	cin>>n;
//
//	f[0] = f[1] = 1;
//
//	for(int i=2; i<=n;i++){
//		f[i] = f[i-1] + f[i-2]; // recursive equation
//	}
//	cout<<f[n]<<endl;
//
//
//	// Fibnocai sequence not use array, but it cant storage other num.
//	ll a=1,b=1,c=1;
//
//	for(int i=2;i<=n;i++){
//		c = a + b;
//		a = b;
//		b = c;
//	}
//	cout<<c<<endl;


// Yanghi Trangle output num

	using ll = long long ;
	const int N = 55;
	
	ll f[N][N];

	int n,m;
	cin>>n>>m;

	for(int i=0; i<N; i++) {
		for(int j=1; j<=i; j++) {
			if( j == 1) {
				f[i][j] = 1;
			} else {
				f[i][j] = f[i -1][j-1] + f[i-1][j]; // the dp: recursive equation
			}
		}
	}

	cout<<f[n][m]<<endl;




	return 0;
}
