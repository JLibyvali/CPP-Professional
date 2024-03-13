#include <iostream>
#include <algorithm>


using namespace std;


// 1

//const int mod = 1e9 + 7;


int main() {
	/*
	input: one integer
	Output: Fibonaci-sequence N  mod (1e9 + 7)

	*/

//	int f[10010] { };
//	int n;
//
//	cin>>n;
//
//	f[1] = 1;
//	f[2] = 1;
//
//	for(int i=3; i<=n; i++) {
//
//		f[i] = (f[i-1] + f[i-2]) % mod;
//	}
//
//
//	cout<<f[n]<<endl;


	/*
	Input: one matrix,
	Output: retate 90 degress the matrix in clockwise
	*/

//	int g[210][210] { };
//	int n,m;
//	cin>>n>>m;
//
//
//	for(int i=0;i<n;i++){
//
//		for(int j=0;j<m;j++){
//			cin>>g[i][j];
//		}
//
//	}
//
//	for(int i=0;i<m;i++){
//		for(int j =0;j<n;j++){
//
//			if(j == n-1){
//				cout<<g[n-1-j][i]<<endl;
//				break;
//			}
//			cout<<g[n - 1 - j][i]<<" ";
//
//		}
//	}

	/*
	Input: n * m matrix. You have to find the biggest sub-matrix that should not be '0-matrix'.
	Output: The biggest sub-matrix in A.

	*/

//	int n,m,ans;
//	int mat[60][60] { };
//	ans = -1005;	//the worst result;
//
//	cin>>n>>m;
//
//	for(int i=0;i<n;i++){
//
//			for(int j=0;j<m;j++){
//
//				cin>>mat[i][j];
//			}
//	}
//
//	for(int i=0;i<n;i++){	// up
//		for(int j=i;j<n;j++){	//down
//			for(int k=0;k<m;k++){	//left
//				for(int l=k;l<m;l++){	//right
//
//					int temp = 0;
//					for(int p=i;p<=j;p++){	//current
//						for(int q=k;q<=l;q++){
//							temp += mat[p][q];
//						}
//					}
//
//					if(temp > ans){
//						ans = temp;
//					}
//
//				}
//			}
//		}
//	}
//
//
//	cout<<ans<<endl;


	/*
	Input: N integers.
	Output: sort sequence and remove the repeated num;

	*/

//	int N;
//	cin >>N;
//
//	int num[110],ans[110];
//	for(int i=0;i<N;i++){
//		cin>>num[i];
//	}
//
//
//	sort(num,num+N);
//
//	int m = 0;
//
//	for(int i=0;i<N;i++){
//		if(i != 0 && num[i] != num[i-1]){
//			ans[m] = num[i-1];
//			m++;
//		}
//	}
//
//	ans[m++] = num[N-1];	// the end num.
//	cout<<m<<endl;
//
//	for(int i=0;i<m;i++){
//		if( i == N-1){
//			cout<<ans[i]<<endl;
//		}
//
//		cout<<ans[i]<<" ";
//	}
//

	/*
	Input: N integers,l1,r1,l2,r2;
	Output: sort
	*/

//	int n,l1,r1,l2,r2;
//	int num[100010];
//
//	cin>>n>>l1>>r1>>l2>>r2;
//
//	for(int i=0; i<n; i++) {
//
//		cin>>num[i];
//
//	}
//	
//	sort(num +(l1-1),num+ r1);
//	sort(num +(l2 -1),num + r2,greater<int>());
//	
//	
//	for(int i=0;i<n;i++){
//		if(i == n-1){
//			cout<<num[i]<<endl;
//			break;
//		}
//		cout<<num[i]<<" ";
//	}

/* 
Input: 2 integers.
Output: after base conversation.

*/
//	
//	int n,b,m,now;
//	char ans[110];
//	cin>>n>>b;
//	
//	
//	if(n < 0){
//		cout<<"-";
//		n = -n;
//	}
//	
//	
//	m = 0;
//	while(n){
//		
//		now = n % b;
//		if(now <=9){
//			ans[m] = '0' + now;
//			m++;
//		}else{
//			ans[m] = 'A' + now - 10;
//			m++;
//		}
//		
//		n /= b;
//		
//	}
//	
//	if(m==0){ 
//	cout<<0<<endl;
//	}
//	for(int i=m-1;i>=0;i--){
//		cout<<ans[i];
//	}
//	
	return 0;
}
