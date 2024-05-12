#include <iostream>


using namespace std;


//#######################CUT tree1;
//int n,m,X,Y;
//char mp[110][110];
//bool vis[110][110];
//
//int dir[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
//int  ans = 1e7;

//
//bool in(int x , int y){
//	return 0 <= x && x < n && 0 <= y && y < m;
//}
//
//void dfs(int x, int y , int stp){
	
//	if(stp >= ans){	//Cut
//		return;
//	}
//	
//	if(mp[x][y] == 'T'){	//End
//		ans = stp;
//		return;
//	}
//	
//	vis[x][y] = 1;
//	
//	for(int i=0;i<4;i++){
//		int tx = x + dir[i][0];
//		int ty = y + dir[i][1];
//		
//		if(in(tx,ty) && mp[tx][ty] != '*' && !vis[tx][ty] ){
//			
//			dfs(tx,ty,stp+1);
//			
//		}
//	}
//	
//	vis[x][y] = 0;
	
//}


//###########Even and Odd

int T;

const int N = 10;
char mp[N][N];
bool vis[N][N];

int dir[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
bool f;

void dfs(int x, int y,int t){
	if(f){
		return;
	}
	if(t == T){
		if(mp[x][y] == 'D'){
			f = true;
		}
		return ;
	}
	
	vis[x][y] = true;
	for(int i=0; i<4;i++){
		int dx = x + dir[i][0];
		int dy = y + dir[i][1];
		
		if(in(dx,dy) && mp[x][y] != 'X' && !vis[x][y]){
			dfs(dx,dy,t+1);
		}
		
	}

	
	vis[x][y] = false;
	
	
}

int  main(){
	
//	cin>>n>>m;
//	for(int i=0; i<n;i++){
//		cin>>mp[i];
//	}
//	
//	for(int i=0;i<n;i++){
//		for( int j=0;j<m;j++){
//			if(mp[i][j] == 'S'){
//				X = i;
//				Y = j;
//			}
//		}
//	}
//	dfs(X,Y,0);
//	cout<<ans<<endl;

//##########################CUT tree2: Odd and Even cut;

	cin>>n>>m>>T;
	for(int i=0;i<n;i++){
		cin>>mp[i];
	}
	
	
	int sx,sy,ex,ey;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(mp[i][j] == 'S'){
				sx = i, sy = j;
			}
			if(mp[i][j] == 'D'){
				ex = i;
				ey = j;
			}
		}
	}
	
	
	if((sx + sy + ex +ey + T) % 2 != 0){
		cout<<"NO"<<endl;
	}else{
		
		f = false;
		dfs(sx,sy,0);
		if(f){
			cout<<"YES"<<endl;
		}else {
			cout<<"NO"<<endl;
		}
			
	}
	
	
	return 0;
}
