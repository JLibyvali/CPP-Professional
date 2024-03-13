#include <iostream>
#include <algorithm>
#include <cmath>


using namespace std;


int main() {

//	int n,m,cnt=0;
//	cin>>n>>m;
//
//	bool f = false;
//
//	for(int i=n; i<=m; i++) {
//
//		int tmp = i;
//
//		while(tmp) {
//			if(tmp % 10 == 4) {
//				f = true;
//			}
//			tmp /= 10;
//		}
//
//		if(!f) {
//			cnt ++;
//		}
//		f  = false;
//	}
//
//	cout<<cnt<<endl;


	/*
	Input : a^2 + b^2 = c^2 = n, input 'n'
	Output: a,b,c

	*/

//	int n;
//	cin>>n;
//
//
//	for(int a = 1; a*a <= n; a++) {
//
//		for(int b = a+1; a*a + b*b <= n; b++) {
//
//			for(int c = b+1;a*a + b*b + c+c <= n;c++){
//
//				if(a*a + b*b +c*c ==n){
//					cout<<a<<" "<<b<<" "<<c<<" "<<endl;
//				}
//
//			}
//
//		}
//
//	}

	/*
	Input: two integrs n and m,n * m matrix.
	Output: The biggest sub-matrix elements plus.

	*/
//
//	int n,m;
//	int ma[55][55];
//	cin>>n>>m;
//
//
//	for(int i=0;i<n;i++){
//		for(int j=0;j<m;j++){
//
//			cin>>ma[i][j];
//
//		}
//	}
//
//	int ans = -1005;
//
//
//	for(int i=0; i<n; i++) {	//up
//		for(int j=i; j<n; j++) {	//down
//			for(int k =0; k<m; k++) {	//right
//				for(int l=k; l<m; l++) {	//left
//
//					int tmp=0;
//					for(int p=i;p<=j;p++){
//						for(int q = k;q<=l;q++){
//
//							tmp += ma[p][q];
//
//						}
//					}
//
//
//					if(tmp > ans){
//						ans = tmp;	// At least, upgrade ans one time.
//					}
//
//				}
//			}
//		}
//	}
//
//	cout<<ans<<endl;

	/*
	Input: N, a*a + b*b + c*c + d*d = N,
	Output: foind one group a,b,c,d;

	*/
//	int n;
//	cin>>n;
//
//	for(int a=0; a*a<=n; a++) {
//		for(int b=a; a*a + b*b <= n; b++) {
//			for(int c= b; a*a + b*b +c*c <=n; c++) {
//
//				int d =sqrt(n - a*a - b*b -c*c);
//
//				if(a*a + b*b +c*c +d*d == n) {
//					cout<<a<<" "<<b<<" "<<c<<" "<<d	<<" "<<endl;
//					return 0;
//				}
//
//
//			}
//		}
//	}

	/*
	input: One integer, and int array.
	Output: the best.

	*/
//	int a[1000];
//
//	int n,sum,ans;
//	cin>>n;
//
//	for(int i=0;i<n;i++){
//		cin>>a[i];
//	}
//
//	sum = 0;
//	ans = 0;
//
//	for(int i=0;i<n;i++){
//
//		sum = 0;
//		for(int j=i;j<n;j++){
//
//			 sum  += a[j];
//
//			 if( sum > ans ){
//			 	ans = sum;
//			 }
//
//		}
//
//
//	}
//
//	cout<<ans;



	int n;
	int L[110];

	cin>>n;
	for(int i=0; i<n; i++) {
		cin>>L[i];
	}


	int ans = 10010;

	for(int i=0; i<n; i++) {

		int tmp;
		int j = i+1;

		tmp = abs(L[i] - L[j]);
		if(tmp < ans) {
		
			ans = tmp;
			
		}

		j++;
		
		
		if(j == n-1) {
			break;
		}


	}


	cout<<ans<<endl;

	return 0;
}
