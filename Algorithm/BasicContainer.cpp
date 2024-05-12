#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using  namespace std;


// STL set
//struct Point{
//
//	int x,y;
//
//	bool operator<(const Point &rhs ) const{
//
//		if(x == rhs.x){
//			return  y <  rhs.y;
//		}else {
//			return x < rhs.x;
//		}
//
//	}
//
//};
//
//
//struct Person {
//
//	int height;
//	int weight;
//	int age;
//
//	Person()  = default;
//
//	Person(int _h,int _w,int _a):height(_h),weight(_w),age(_a) {
//	}
//
//	bool operator<(const Person &rhs) const {
//
//		if(height != rhs.height) {
//
//			return height < rhs.height;
//
//		} else if(weight != rhs.weight {
//
//		return  weight < rhs.weight;
//
//	} else {
//		return age < rhs.age;
//	}
//}
//
//};

//###########################



int main() {

//	STL set
//	int n;
//	cin>>n;
//
//	set<Point> s1;
//	for(int i=0;i<n;i++){
//
//		Point tmp;
//
//		cin>>tmp.x>>tmp.y;
//
//		s1.insert(tmp);
//	}
//
//
//	for(auto const& ele:s1){
//
//		cout<<ele.x<<" "<<ele.y<<endl;
//	}

//	STL map

//	map<int,map<string,int> > m1;
//
//	int n;
//	cin>>n;
//
//	for(int i=0;i<n;i++){
//
//		string name;
//		int id;
//		cin>>id>>name;
//
//		m1[id][name]++;
//
//	}
//
//	for(const auto& ele1: m1){
//		for(const auto& ele2 : ele1.second){
//
//			cout<<"[ "<<ele2.second<<"  "<<ele2.first<<" ]"<<endl;
//
//		}
//	}

	/*
	Input: n lines sawtooth matrix. 'n' means n lines, 'm' means total elements num

	Output: the matrix

	*/
//
//	int n,m;
//
//	cin>>n>>m;
//
//	vector<int>  ma[10010];
//
//	for(int i=0; i<m; i++) {
//
//		int x,y;
//		cin>>x>>y;
//
//		ma[x].push_back(y);
//
//	}
//
//	for(int i=1	; i<=n; i++) {
//
//		if(ma[i].empty()) {
//
//			cout<<" "<<endl;
//
//		} else {
//
//			for(const auto& ele : ma[i]) {
//
//				cout<<ele<<" ";
//			}
//			cout<<endl;
//
//		}
//
//	}
	/*
	Input : 'n' and 'm'  integer,  search 'm' is in 'n' or not.
	Ouput: 'm' line ,yes or no

	*/
//
//	int n,m,H,W,A;
//	cin>>n>>m;
//	set<Person> s1;
//
//
//	for(int i=0; i<n; i++) {
//
//		cin>>H>>W>>A;
//		s1.insert(Person(H,W,A));
//	}
//
//	for(int i=0; i<m; i++) {
//		cin>>H>>W>>A;
//
//		if(s1.count(Person(H,W,A))) {
//			cout<<"yes"<<endl;
//		} else {
//			cout<<"no"<<endl;
//		}
//	}


	/*
	Input: n line, each line contains book-number;
	Output: Diferent books num, out put by dictionary order.

	*/

//	int n;
//	cin>>n;
//	map<string,int> ma;
//
//	for(int i=0;i<n;i++){
//		string tmp;
//		cin>>tmp;
//		ma[tmp]++;
//	}
//
//	int len = ma.size();
//	cout<<len<<endl;
//
//
//	for(const auto& ele : ma){
//
//		cout<<ele.first<<" "<<ele.second<<endl;
//	}



	/*
	STL move jim
	*/

//	int n,m;
//	cin>>n>>m;
//
//
//
//	vector<int>	 vec[10010];
//
//	for(int i=1; i<=n; i++) {
//		vec[i].push_back(i);
//	}
//
//
//	for(int i=1; i<=m; i++) {
//
//		int a,b;
//		cin>>a>>b;
//
//		if(a ==b) {
//			continue;
//		} else {
//
//
//			for(int j=0; j<vec[b].size(); j++) {
//				vec[a].push_back(vec[b][j]);
//			}
//			vector<int>().swap(vec[b]);
//
//		}
//
//	}
//
//	for(int i=1; i<=n; i++) {
//
//		vector<int> tmp = vec[i];
//
//		if( tmp.empty()) {
//
//		} else {
//
//			for(const auto& ele : tmp) {
//
//				if(ele != tmp.back()) {
//					cout<<ele<<" ";
//				}else{
//					cout<<ele;
//				}
//			}
//
//		}
//		cout<<endl;
//	}


	/*
	Input: two sets
	Output: sets' union.

	*/

//
//	int n,m;
//	set<int> A,B;
//
//
//	cin>>n>>m;
//	for(int i=0;i<n;i++){
//		int tmp;
//		cin>>tmp;
//		A.insert(tmp);
//	}
//	for(int j=0;j<m;j++){
//		int tmp;
//		cin>>tmp;
//		B.insert(tmp);
//	}
//
//
//	for(const auto& ele:B){
//
//		A.insert(ele);
//
//	}
//
//	for(const auto& ele: A){
//
//		if(ele == *(A.end()--) ){
//			cout<<ele<<endl;
//		}else {
//			cout<<ele<<" ";
//		}
//
//	}


//############################################################
//
//	int n,op;
//	string ss;
//	set<string> s1;
//
//	cin>>n;
//
//	for(int i=0;i<n;i++){
//		cin>>op>>ss;
//
//		for(int j=0;j<ss.size();j++){
//			if(ss[j] >='A' && ss[j] <= 'Z'){
//				ss[j] = 'a' + (ss[j] - 'A');
//			}
//		}
//
//		if( op ==0){
//			s1.insert(ss);
//		}else{
//
//			if(s1.count(ss)){
//				cout<<"Yes"<<endl;
//			}else{
//				cout<<"No"<<endl;
//			}
//		}
//	}


//#########################################3

//	int n,num;
//	map<int,int> ma;
//
//	cin>>n;
//
//	for(int i=0;i<n;i++){
//		cin>>num;
//		ma[num]++;
//	}
//
//	int ans1,ans2;
//	ans2 = 0;
//
//	for(const auto& ele : ma){
//
//		if(ele.second >= ans2){
//			ans2 = ele.second;
//			ans1 = ele.first;
//		}
//	}
//
//	cout<<ans1<<" "<<ans2<<endl;
//

//#########################
/*
Input: 5
apple shandong 3
pineapple guangdo
sugarcane guangdo
pineapple guangdo
pineapple guangdo

Output:
pineapple guangdo
guangdong
   |----pineapple
   |----sugarcane
shandong
   |----apple(3)


*/
//
//
//	int n,m;
//	string name,place;
//	cin>>n;
//	
//	map<string,map<string,int> > mp;
//	
//	for(int i=0;i<n;i++){
//		
//		cin>>name>>place>>m;
//		mp[place][name] += m;
//	}
//	
//	
//	
//	for(const auto& ele : mp){
//		cout<<ele.first<<endl;
//		for(const auto& ele1 : ele.second){
//			cout<<"   |----"<<ele1.first<<"("<<ele1.second<<")"<<endl;
//		}
//		
//		
//	}




	return 0;
}
