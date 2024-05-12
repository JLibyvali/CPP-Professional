#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


/*
int g[40];
int s[6] {0};
Input: The class students num and their grades

Output: grades sort and  groups.

*/


//bool cmp(int x,int y){
//
//	if(x % 3 == y % 3){
//		return (x <  y);
//	}else{
//		return (x % 3 < y % 3);
//	}
//
//
//
//}




struct Student {

	string name;
	int YW,SX,YY,DL;
	int total;
	Student() {}
	Student(string _name, int _YW,int _SX, int _YY,int _DL): name(_name), YW(_YW), SX(_SX), YY(_YY), DL(_DL) {

		total = (YW + SX + YY + DL);
	}

};
bool cmp(Student x, Student y) {
	
	return x.total > y.total;

}
int main() {


//	int num;
//	scanf("%d",&num);
//
//	for(int i=0;i<num;i++){
//
//		scanf("%d",&g[i]);
//	}
//
//
//	sort(g,g+(num+1),greater<int>());
//
//	for(int i =0;i<num;i++){
//
//		if(g[i] == 100){
//			s[0]++;
//			continue;
//		}else if(g[i] >=90 && g[i] <=99){
//			s[1]++;
//			continue;
//		}else if(g[i] >= 80 && g[i] <= 89){
//			s[2] ++;
//			continue;
//		}else if(g[i] >= 70 && g[i] <= 79){
//			s[3]++;
//			continue;
//		}else if(g[i] >= 60 && g[i] <=69){
//			s[4]++;
//			continue;
//		}else{
//
//			s[5]++;
//			continue;
//		}
//	}
//
//
//
//	for(int i=0;i<num;i++){
//		printf("%d\n",g[i]);
//	}
//
//	for(int i=0;i<6;i++){
//
//		printf("%d ",s[i]);
//
//	}
//
//
//

	/*
	Input: N integers
	Output: Sort these N integers by their remainder.

	*/
//	int n;
//	int num[105];
//	scanf("%d",&n);
//
//	for(int i=0;i<n;i++){
//
//		scanf("%d",&num[i]);
//	}
//
//	sort(num,num+n,cmp);
//
//	for(int i=0;i<n;i++){
//		if(i == n -1){
//			printf("%d\n",num[i]);
//			break;
//		}
//
//		printf("%d ",num[i]);
//
//	}

	/*
	Input: number 'N', and every students' name and grades.

	Output:	three total grades most student.

	*/

	int n;
	Student stu[45] { };

	scanf("%d",&n);

	for(int i=0; i<n; i++) {

		string name;
		int a,b,c,d;
		cin>>name>>a>>b>>c>>d;
		stu[i] = Student(name,a,b,c,d);

	}

	sort(stu,stu + n, cmp);
	
	for(int i =0;i<3;i++){
		cout<<stu[i].name<<endl;
	}


	return 0;
}
