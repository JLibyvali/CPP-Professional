#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

// 1
//double num[110];
//static const double  EPSILON = 1e-6;
//
//bool cmp(double x, double y){
//
//	double dx  = fabs(x - round(x));	//round(), throw '.num' < four, get big one '.num >= 5'
//	double dy  = fabs(y -  round(y));
//
//	if( fabs(dx - dy) < EPSILON){
//		return x < y;
//	}
//
//	return dx < dy ;
//}


// 3
//char c[10010];

// 4
//int num [110];
//
//bool cmp(int x,int y) {
//
//	int xx =x , yy =y;
//	int suma = 0, sumb = 0;
//
//	while(x) {
//		suma += x % 10;
//
//		x /= 10;
//	}
//
//	while(y) {
//		sumb += y %10;
//
//		y /= 10;
//	}
//
//
//	if(suma == sumb) {
//
//		return xx < yy;
//	}
//
//	return suma <sumb;
//}




// 5

//struct Student {
//
//	int score;
//	int id;
//
//};
//
//
//bool cmp(Student a,Student b) {
//
//	return a.score > b.score;
//
//};

// 6


//struct Student {
//
//	string name;
//	int Y,S,YY,K;
//
//	Student(){}
//
//};
//
//bool cmpY(Student x, Student y) {
//
//	return x.Y > y.Y;
//}
//
//bool cmpS(Student x, Student y) {
//
//	return x.S > y.S;
//}
//
//bool cmpYY(Student x, Student y) {
//	return x.YY > y.YY;
//}
//
//bool cmpK(Student x, Student y) {
//
//	return x.K > y.K;
//}
//
//bool cmp(Student x,Student y) {
//
//		int sumx = 0,sumy = 0;
//		sumx = (x.Y + x.S + x.YY + x.K);
//		sumy = (x.Y + x.S + x.YY + x.K);
//		
//		return sumx > sumy;
//	
//}






int main() {
	
	
	
	/*
	Input: N double num,sort it.
	Judge two double num is equal or not should use below:
	if (fabs( a - b) < EPSILON){
		// then double a  =b;
	}
	Output:

	*/

//	int n;
//
//	scanf("%d",&n);
//
//	for(int i=0;i<n;i++){
//		scanf("%lf",&num[i]);
//	}
//
//
//	sort(num,num+n,cmp);
//
//	for(int i=0;i<n;i++){
//
//		if(i == n -1 ){
//
//			printf("%.6f",num[i]);
//			break;
//		}
//		printf("%.6f ",num[i]);
//	}

	/*
	Input: N students,every one's grades
	Output: grade line and winners num;

	*/
//
//	int N;
//	int g[100010];
//	scanf("%d",&N);
//
//	for(int i =0;i<N;i++){
//		scanf("%d",&g[i]);
//	}
//
//	sort(g,g+N,greater<int>());
//
//
//	printf("%d ",g[ (N -1) /2  ]);	//grade line;
//
//	int ans = 0;
//
//	for(int i=0;i<N;i++){
//
//		if(g[i] >= g[ ( N -1 ) /2]){
//			ans ++;
//		}else{
//			break;
//		}
//
//
//	}
//	printf("%d\n",ans);



	/*
	Input: N ,l1,l2,r1,r2;

	Output: (l1,r1) sort by ascending order,(l2,r2) sort by descending orde.

	*/

//
//	int N,l1,l2,r1,r2;
//	int num[10010];
//
//	scanf("%d%d%d%d%d",&N,&l1,&r1,&l2,&r2);
//
//	for(int i=0;i<N;i++){
//		scanf("%d",&num[i]);
//	}
//
//	sort(num + (l1-1), num + r1);
//	sort(num + (l2 - 1), num + r2,greater<int>());
//
//	for(int i =0;i<N;i++){
//		if(i == N -1){
//			printf("%d\n",num[i]);
//			break;
//		}
//		printf("%d ",num[i]);
//	}



	/*
	Input : one string made up with "R G B"

	Output: sorted string by "R G B" in dictionary,and next line. one integer that  in "1R2G3B" order.

	*/
//	int len;
//	scanf("%s",&c);
//
//	len =  strlen(c);
//	sort(c,c+len);	// In ASCII code
//
//
//	int r=0,g=0,b=0;
//
//
//
//	for(int j =0 ; j<len;j++){
//
//		if(c[j] == 'R'){
//			r ++;
//		}else if(c[j]  == 'G'){
//			g++;
//		}else{
//			b++;
//		}
//	}
//
//
//	printf("%s\n",c);
//	printf("%d", min(r,min(g / 2,b / 3)));


	/*
	Input: N nums, then plus each digit and sort the result.
	Output:
	sort result
	//*/
//
//	int N;
//	scanf("%d",&N);
//
//	for(int i =0;i<N;i++){
//
//		scanf("%d",&num[i]);
//	}
//
//	sort(num,num+N,cmp);
//
//	for(int i=0;i<N;i++){
//		if(i != N -1){
//			printf("%d ",num[i]);
//		}else {
//			printf("%d\n",num[i]);
//		}
//	}
//
//	int N;
//
//	scanf("%d",&N);
//	Student stu[110] { };
//
//	for(int i =0;i<N;i++){
//
//		scanf("%d",&stu[i].score);
//		stu[i].id = i+1;
//	}
//
//	sort(stu,stu+N,cmp);
//
//
//	for(int i=0;i<N;i++){
//
//		if( i == N-1) {
//			printf("%d\n",stu[i].id);
//			break;
//		}
//		printf("%d",stu[i].id);
//
//	}



//
//	int N;
//	scanf("%d",&N);
//
//
//	Student stu[110];
//
//	for(int i=0; i<N; i++) {
//
//		cin>>stu[i].name>>stu[i].Y>>stu[i].S>>stu[i].YY>>stu[i].K;
//
//	}
//
//	sort(stu,stu+N,cmpY);
//	for(int i =0 ; i<4; i++) {
//
//		if(i == 3) {
//			cout<<stu[i].name<<endl;
//			break;
//		}
//		cout<<stu[i].name<<" ";
//	}
//
//	sort(stu,stu+N,cmpS);
//	for(int i =0 ; i<4; i++) {
//
//		if(i == 3) {
//			cout<<stu[i].name<<endl;
//			break;
//		}
//		cout<<stu[i].name<<" ";
//	}
//
//	sort(stu,stu+N,cmpYY);
//	for(int i =0 ; i<4; i++) {
//
//		if(i == 3) {
//			cout<<stu[i].name<<endl;
//			break;
//		}
//		cout<<stu[i].name<<" ";
//	}
//
//	sort(stu,stu+N,cmpK);
//	for(int i =0 ; i<4; i++) {
//
//		if(i ==3) {
//			cout<<stu[i].name<<endl;
//			break;
//		}
//		cout<<stu[i].name<<" ";
//	}
//
//
//	sort(stu,stu+N,cmp);
//	
//	for(int i =0; i<4; i++) {
//		if(i == 3) {
//			cout<<stu[i].name<<endl;
//			break;
//		}
//		cout<<stu[i].name<<" ";
//	}







	return 0;
}
