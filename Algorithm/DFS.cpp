#include <iostream>


using namespace std;

// Maze

//char maze[110][110];
//bool vis[110][110];
//int n,m;
//
//
//int dir[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
//
//
//bool in(int x , int y) {
//	return 0 <= x &&  x < n && 0 <= y && y<m;
//}
//
//bool dfs(int x, int y) {
//
//	if(maze[x][y] == 'T') {
//		return  true;
//	}
//
//	vis[x][y] = true;
//	maze[x][y] = 'm';
//
//	for(int i=0; i< 4 ; i++){
//		int tx = x + dir[i][0];
//		int ty = y + dir[i][1];
//
//		if( in(tx,ty) && maze[tx][ty] != '*' && !vis[tx][ty]){
//			if(dfs(tx,ty)){
//				return true;
//			}
//		}
//	}
//
//	maze[x][y] = '.';
//	vis[x][y] = false;
//
//	return false;
//}


// Chess

//char q[10][10];
//bool vis[10][10];
//bool P;
//int dir[8][2] = {{-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1}};	// eight directions
//
//bool in ( int x, int y){
//
//	return  0<=x &&  x< 10 && 0 <= y && y <10;
//
//}
//void dfs(int x, int y){
//
//
//	if(q[x][y] == 'T'){
//		P = true;
//		return;
//	}
//
//	vis[x][y] = true;
//
//	for(int i=0;i<8;i++){
//
//		int tx = x + dir[i][0];
//		int ty = y + dir[i][1];
//
//		if( in(tx,ty) && !vis[tx][ty] && q[tx][ty] != '#') {
//			 dfs(tx,ty);
//		}
//	}
//
//}


// ############## Meet question
//int n,m;
//char ma[110][110];a
//bool vis[110][110][2];
//
//bool f = false;
//
//void dfs(int x,int y,int who) {
//
//	if(x < 0 || x >= n || y < 0 || y >= m || vis[x][y][who] || ma[x][y] == '#') {
//		return ;
//	}
//	
//	vis[x][y][who] = true;
//	
//	dfs(x - ( 2 - who),y,who);
//	dfs(x,y - (2 - who),who);
//	dfs(x + (2 - who),y,who);
//	dfs(x,y + (2 -who), who);
//
//
//}


int main() {

	/*
	Input : string maze;
	*/

//	cin>>n>>m;
//
//	for(int i=0; i<n; i++) {
//
//		cin>>maze[i];

//	}
//
//	int X, Y;
//	for(int i=0; i<n; i++) {
//		for(int j=0; j<m; j++) {
//			if(maze[i][j] == 'S') {
//
//				X = i;
//				Y = j;
//			}
//		}
//	}
//
//	if(dfs(X,Y)) {
//
//		for( int i=0; i<n; i++) {
//			cout<<maze[i]<<endl;
//		}
//	} else {
//		cout<<"No"<<endl;
//	}

	/*
	Input: Chinese chess, 'horse'

	*/

//	for(int i=0;i<10;i++){
//		cin >> q[i];
//	}
//
//	int x,y;
//	for(int i=0;i<10;i++){
//		for(int j=0 ; j<10;j++){
//
//			if(q[i][j] == 'S'){
//				x = i;
//				y = j;
//			}
//		}
//	}
//
//	dfs(x,y);
//
//	if(P){
//		cout<<"YES"<<endl;
//	}else{
//		cout<<"Nope"<<endl;
//	}

//############################################Meet question
//
//	cin>>n>>m;
//	int x, y;
//	bool ans = false;
//
//	for(int i=0; i<n; i++) {
//		cin>>ma[i];
//	}
//
//	for(int i=0; i<n; i++) {
//		for(int j=0; j<m; j++) {
//			if(ma[i][j] == 'w') {
//				x = i;
//				y = j;
//			}
//		}
//	}
//	dfs(x,y,0);
//
//	for(int i=0; i<n; i++) {
//		for(int j=0; j<m; j++) {
//			if(ma[i][j] == 'g') {
//				x = i;
//				y = j;
//			}
//		}
//	}
//	dfs(x,y,1);
//
//
//	for(int i=0; i<n; i++) {
//		for(int j=0; j<m; j++) {
//			if(vis[i][j][0] && vis[i][j][1]) {
//				ans = true;
//			}
//		}
//	}
//
//	if(ans){
//		cout<<"YES"<<endl;
//	}else{
//		cout<<"No"<<endl;
//	}

	return 0;
}
