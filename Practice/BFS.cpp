#include <iostream>
#include <queue>

using  namespace std;


//###########MAZE : min steps;
//char mp[110][110];
//int n,m,X,Y;
//bool vis[110][110];
//
//int dir[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
//
//bool in (int x , int y){
//	return  0 <= x && x < n && 0<= y && y <m;
//}
//
//struct point{
//	int x, y ,stp;
//	point() = default;
//	point(int _x, int _y,int _sp) : x(_x) , y(_y), stp(_sp){
//	}
//};
//
//int bfs(int x, int y){
//
//	queue<point> q;
//	q.push(point(x,y,0));
//
//	vis[x][y] = true;
//
//	while(!q.empty()){
//		point tmp = q.front();
//		q.pop();
//
//		for( int i=0;i<4;i++){
//			int dx = tmp.x + dir[i][0];
//			int dy = tmp.y + dir[i][1];
//
//			if(in(dx,dy) && !vis[dx][dy] && mp[dx][dy] != '*'){
//				if(mp[dx][dy] == 'T'){
//					return tmp.stp + 1;
//				}else{
//					vis[dx][dy] = true;
//					q.push(point(dx,dy,tmp.stp + 1));
//				}
//			}
//		}
//	}
//
//	return -1;
//
//}


//########################3



int main() {

// ##Example : Baoshu!.
//	int n,m	;
//	cin >> n >>m;
//	queue<int> q;
//
//	for(int i =1 ; i<= n;i++){
//		q.push(i);
//	}
//
//	int cur =1;
//
//	while(q.size() > 1){
//		int x = q.front();
//		q.pop();
//
//		if(cur == m){
//			cur =1;
//		}else{
//			q.push(x);
//			cur++;
//		}
//	}
//
//
//	cout<<q.front()<<endl;

//##########MAZE : min steps

//	cin>>n>>m;
//	for(int i=0;i<n;i++){
//		cin>>mp[i];
//	}
//
//	for(int i=0;i<n;i++){
//		for(int j=0;j<m;j++){
//			if(mp[i][j] == 'S'){
//				X = i, Y = j;
//			}
//		}
//	}
//
//	cout<<bfs(X,Y)<<endl;



//###########Move in coordinate system: in min steps
	int n,A,B,now,stp;
	bool vis[5010];
	
	
	cin>>n>>A>>B;

	queue<pair<int,int> > Q;	// position and 'steps'
	Q.push(make_pair(A,0));

	vis[A] = true;

	while(!Q.empty()) {

		now = Q.front().first;
		stp = Q.front().second;
		
		Q.pop();
		
		if(now == B){
			cout<<stp<<endl;
			break;
		}
		
		if(now + 1 <= n && !vis[now+1]){
			Q.push(make_pair(now + 1,stp + 1));
			vis[now + 1] = true;
		}
		
		if(now - 1 >=0 && !vis[now - 1]){
			Q.push(make_pair(now - 1,stp +1));
			vis[now - 1] = true;
		}
		if(now * 2 <= n && !vis[now * 2]){
			Q.push(make_pair(now*2,stp+1));
			vis[now*2] = true;
		}
			
	}


	return 0;
}
