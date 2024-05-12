#include <iostream>
#include <algorithm>


using namespace std;


// 1

//const int mod = 1e9 + 7;

// 5
//int num[1010],digit[1010];
//bool Judge(int _x){
//
//	int count = 0;
//	while(_x){	// dividing one Integer to digit array.
//
//		digit[count] =  _x % 10;
//		count ++;
//		_x /= 10;
//	}
//
//	for(int i=0;i< count /2;i++){
//
//		if(digit[i] != digit[count -i -1]){
//			return false;
//		}
//	}
//	return  true;
//
//}
//
//
//int rev(int _x){
//
//	int rent = 0;
//
//	while(_x){
//
//		rent = rent * 10 + _x % 10;
//
//		_x /= 10;
//	}
//	return rent;
//
//}



// 6
//int num;
//int digit[10];
//
//
//bool judge(int _x) {
//
//	int index= 0;
//	int sum = 0;
//
//	while(_x) {
//
//		digit[index] = _x % 10;
//		sum += digit[index];
//
//
//		index ++;
//		_x /= 10;
//
//	}
//
//	if(sum != num) {
//
//		return false;
//
//	} else {
//
//		for(int i=0; i < index / 2; i++) {
//
//			if(digit[i] != digit[index - 1 - i]) {
//
//				return false;
//
//			}
//
//		}
//	}
//
//	return true;
//
//}


// 7
//int num;
int digit[4] {};
int r[4];

bool rose(int _x) {

	int ind=0,c;
	c = _x;
	while(_x) {

		digit[ind] = _x % 10;

		ind++;

		_x /= 10;

	}

	int sum;
	sum =0;

	for(int i=0; i<ind;i++) {

		r[i] = (digit[i] * digit[i] * digit[i] * digit[i]);

		sum +=r[i];

	}

	if(sum == c) {
		return  true;

	} else {
		return false;
	}



}




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


	/*
	Input : one integre
	Output: transformation of palindrome number.

	*/

//
//	int n;
//
//	cin>>n;
//
//
//	int m=0;
//
//	num[m++] = n;
//
//
//	while(!Judge(n)){
//
//		n += rev(n);
//		num[m++] = n;
//	}
//
//	cout<< m -1 <<endl;
//
//
//	for(int i=0;i<m;i++){
//
//		if(i == m-1){
//			cout<<num[i]<<endl;
//			break;
//		}
//
//		cout<<num[i]<<"--->";
//
//	}

//	int dy[] = { -1,0,1,0};	//down,left,up,right.
//	int dx[] = {0,-1,0,1};
//
//
//	int n,x,direct;
//	int curx,cury;
//	char op[20];
//
//
//	direct = 3;
//	curx = cury = 0;
//
//	cin>>n;
//
//	for(int i=0;i<n;i++){
//
//		cin>>op>>x;
//
//		if(op[0] == 'b'){
//			direct = (direct + 2) % 4;
//		}else if(op[0] == 'l'){
//			direct = ( direct + 3) % 4;
//		}else if(op[0] == 'r'){
//			direct = ( direct + 1) % 4;
//		}
//
//		cury += dy[direct] * x;
//		curx += dx[direct] * x;
//
//	}
//
//
//	cout<<curx<<" "<<cury<<endl;

//
//	cin >> num;
//	bool find =false;
//
//	for(int i=10000; i<1000000; i++) {
//
//		if(judge(i)) {
//
//			cout<<i<<endl;
//			find = true;
//
//		}
//
//	}
//
//	if(!find) {
//
//		cout<<-1<<endl;
//
//	}


	/*
	Input : one Integer, judge it is 'rose-number' or not.
	Output: the result num;

	*/
	cin>>num;

	if(num < 1000 || num > 9999) {
		cout<<"error!"<<endl;

	} else {

		for(int i=1000; i<=num; i++) {

			if(rose(i)){

				cout<<i<<endl;
			}
		}
	}

	



	return 0;
}
