#include <iostream>

using namespace  std;

// ############################Trangle
//int n,p[15],sum;
//bool vis[15],f;
//
//void dfs(int num,int _sum,int now) {
//
//	if(f) {
//		return;
//	}
//	if(num == 3) {
//		f = true;
//		return;
//	}
//
//	if(_sum == sum / 3) {
//
//		dfs(num + 1,0,0);
//
//	}
//
//	for(int i=now; i<n; i++) {
//		if(!vis[i]) {
//			vis[i] = true;
//			dfs(num, _sum + p[i],i+1);
//			vis[i] = false;
//		}
//	}
//
//
//}

// ##################Eigtht queen
bool col[20],x1[20],x2[20];	// Mark position array
int ans;
bool check(int r,int l){
	return !col[l] && !x1[r + l] && !x2[r - l + 8];
}

void dfs(int r){
	if(r == 8){
		ans++;
		return ;
	} 
	
	for(int i=0;i<8;i++){
		if(check(r,i)){
			col[i] =  true;
			x1[r + i] = true;
			x2[r - i + 8] = true;
			
			dfs(r + 1);
			col[i] = x1[r + i] = x2[r - i + 8] = false;
			
		}
	}
	
	
}

int main() {
//
//	cin>>n;
//
//	for(int i=0; i<n; i++) {
//		cin>>p[i];
//		sum += p[i];
//	}
//
//	if(sum % 3 != 0) {
//		cout<<"No"<<endl;
//	} else {
//		dfs(0,0,0);
//		if(f) {
//			cout<<"Yes"<<endl;
//		} else {
//			cout<<"NO"<<endl;
//		}
//
//	}

//#################Eight quenn	
	dfs(0);
	cout<<ans<<endl;


	return 0;
}
