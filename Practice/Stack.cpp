#include <iostream>
#include <stack>
#include <vector>


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
stack<int> S[3];
void move(int x, int y) {

	int  tmp = S[x].top();
	S[x].pop();

	S[y].push(tmp);

	cout<< x <<"--->"<< y <<endl;

}

void hanoi(int A, int B, int C, int n) {

	if(n == 1) {
		move(A,C);
		return;
	}

	hanoi(A,C,B,n-1);
	move(A,C);
	hanoi(B,A,C,n-1);

}

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
Input: Hanoi least steps.

*/



	return 0;
}
