#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <string>


using namespace std;
//
//struct Stack {
//
//
//	int data[10000];
//	int top = -1;
//
//	void push(int x) {
//		top++;
//		if(top < 10000) {
//			data[top] = x;
//		} else {
//			top--;
//			cout<<"Stack overflow"<<endl;
//		}
//	}
//
//	void pop() {
//
//		if(top > -1) {
//			top--;
//		}
//	}
//
//	int topval() {
//
//		if(top > -1) {
//			return data[top];
//		}
//	}
//
//};


//######Recursion
//long long f(int x){
//
//	if( x<= 0){
//		return 0;
//	}
//
//	if(x ==1){
//		return 1;
//	}
//
//	if(x > 1 && x % 2 == 0){
//		return (3*f(x / 2) - 1);
//	}
//
//	if(x > 1 && x % 2 ==1){
//		return (3*f((x + 1 )/ 2 ) - 1);
//	}
//
//}


// Hanota
//stack<int> S[3];
//void move(int x, int y) {
//
//	int  tmp = S[x].top();
//	S[x].pop();
//
//	S[y].push(tmp);
//
//	cout<< x <<"--->"<< y <<endl;
//
//}
//
//void hanoi(int A, int B, int C, int n) {
//
//	if(n == 1) {
//		move(A,C);
//		return;
//	}
//
//	hanoi(A,C,B,n-1);
//	move(A,C);
//	hanoi(B,A,C,n-1);
//
//}



// Recuresion 2
//
//long long f(long long _x, long long _y, long long _p){
//
//	if(_y == 0){
//		return 1 % _p;
//	}else if(_y % 2 == 0){
//		long long tmp = f(_x,_y / 2, _p);
//		return tmp*tmp % _p;
//	}else {
//
//		long long tmp = f(_x,_y / 2 , _p);
//		return (tmp*tmp * _x) % _p;
//	}
//
//}



// Rec 3
//int ans[205],a[205],b[205];
//bool vis[205];
//int n;
//
//int f(int _x){
//
//
//	if( _x >= n){
//		return 0;
//	}
//
//	if( vis[_x]){
//		return ans[_x];
//	}
//
//	return ans[_x] = min(f(_x + a[_x]) , f(_x + a[_x])) + 1;
//
//}

// Rec4

//int gcd(int _x , int _y) {
//
//
//	if(_y == 0) {
//		return _x;
//
//	} else {
//		return gcd(_y, _x % _y);
//	}
//
//}







int  main() {

//	Stack s;
//
//	for(int i=0;i<10;i++){
//		s.push(i);
//	}
//	for(int i=0;i<10;i++){
//		cout<<s.topval()<<endl;
//		s.pop();
//
//	}
//


	/*
	input: 5
		1 2 3 4
	Output: legal


	*/
//	int n;
//	cin>>n;
//
//	vector<int> a(n);
//
//	for(int i=0; i<n; i++) {
//		cin>>a[i];
//	}
//
//
//	stack<int> s;
//	int cur = 1;
//	bool f = true;
//
//	for(int i=0; i<n; i++) {
//
//		while( (s.empty() || s.top()!= a[i]) && cur <= n) {
//			s.push(cur);
//			cur++;
//		}
//
//		if(s.empty() || s.top() != a[i]) {
//
//			f = false;
//			break;
//		} else {
//
//			s.pop();
//
//		}
//
//	}
//
//	if(f){
//		cout<<"legal"<<endl;
//	}else{
//		cout<<"Illegal"<<endl;
//	}

//###########Recursion

//	int n;
//	cin>>n;
//
//	cout<<f(n)<<endl;

	/*
	Input : Hanota
	*/
//
//	int n;
//	cin >> n;
//	for(int i=n; i > 0; i--) {
//		S[0].push(i);
//	}
//
//	hanoi(0,1,2,n);
//
//	cout<<endl;
//	while(!S[2].empty()) {
//
//		cout << S[2].top() <<" ";
//		S[2].pop();
//
//	}


	/*
	Input: t,x,y,p; calculate 'x^y'
	Output: 'x^y' % p;

	*/

//	int t;
//	long long x,y,p;
//	cin>>t;
//
//	while(t){
//		cin>>x>>y>>p;
//		cout<<f(x,y,p)<<endl;
//		t --;
//	}

//	cin>>n;
//	for(int i=0;i<n;i++){
//		cin>>a[i];
//	}
//	for(int i=0;i<n;i++){
//		cin>> b[i];
//	}
//
//
//	cout<<f(0)<<endl;



	/*
	Input : x;
	Output: Max Gongyueshu

	*/

//	int t;
//	int x, y;
//	cin>>t;
//	while(t) {
//
//		cin>>x>>y;
//		cout<<gcd(x,y)<<endl;
//		t--;
//
//	}


//	int n;
//	string op;
//	stack<string> s1,s2;
//	cin>>n;
//
//	for(int i=0; i<n; i++) {
//		cin>>op;
//
//		if(op[0] == 'V') {
//			string tmp;
//			cin>>tmp;
//			while(!s2.empty()) {
//				s2.pop();
//			}
//			
//			s1.push(tmp);
//
//		} else if(op[0] == 'B') {
//
//			if(s1.size() <= 1) {
//				cout<<"Ignore"<<endl;
//				continue;
//			}
//
//			s2.push(s1.top());
//			s1.pop();
//
//		} else {
//			if(s2.empty()) {
//				cout<<"Ignore"<<endl;
//				continue;
//			}
//			
//			s1.push(s2.top());
//			s2.pop();
//		}
//		
//		cout<<s1.top()<<endl;
//	}


	return 0;
}
