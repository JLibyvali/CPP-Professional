#include <bits/stdc++.h>

using namespace std;

// Dijkstra and Astar to solve the 'K-th' minimum value.
// Thought:
//1. build positive direction and negative graph
//2. On negative graph run Dijkstra
//3. On Positive graph run Astar.


// chain forward  star
const int N = 1e5;
const int M = 1e5;

struct edge {
	int v;	// edge's destination
	int w;	// edge's weight
	int next;
	edge() {}
	edge(int _v, int _w, int _next) {
		v = _v;
		w = _w;
		next = _next;
	}
} e[M*2];

int HEAD[N],size,HEADC[N];	// for Astar need tow HEAD[],

void init() {
	memset(HEAD,-1,sizeof(HEAD));
	memset(HEADC,-1,sizeof(HEADC));
	size = 0;
}

void insertD(int head[],int u, int v, int w) {
	
	e[size] = edge(v,w,head[u]);	// create new node, 
	head[u] = size ++;	// make 'head' point to new node.
	
}

// Dijkstra
using PII = pair<int,int>;	// Node information: first:edge's weight , second: current node's adjoining node.

int dis[N];
int vis[N];

void Dijkstra(int src) {

	priority_queue<PII,vector<PII>,greater<PII> > q;	// make min heap;
	memset(dis,0x3f,sizeof(dis));
	memset(vis,false,sizeof(vis));

	dis[src] = 0;
	q.push({0,src});

	while(!q.empty()) {

		PII top = q.top();
		q.pop();

		if(vis[top.second]) {	// if it's marked
			continue;
		}

		vis[top.second] = true;
		
		for(int i = HEADC[top.second]; ~i; i = e[i].next) {	// expanding the min heap, 
			int v = e[i].v;
			int w = e[i].w;

			if(dis[v] > dis[top.second] + w) {
				dis[v] = dis[top.second] + w;
				q.push({dis[v],v});	// update the min heap, 
			}
		}

	}

}


int S,T,K;
struct  node {
	int f;	// f = g + h;
	int v;	// current node
	int d;	// distance

	node(int _f,int _v,int _d) {
		f = _f;
		v = _v;
		d = _d;
	}
	bool operator<(const node& x) const {	// for sort in priority_order via the 'f' value;
		return  f > x.f;	// in increase order. the top is min
	}	// the minimum in the heap top.
};

int cnt[N];	// record out queue times
int Astar(int src) {
	
	memset(cnt,0,sizeof(cnt));
	priority_queue<node> q;	// in increase order.
	
	q.push(node {dis[src],src,0});

	while(!q.empty()) {
		
		node top = q.top();
		q.pop();

		cnt[top.v]++;
		if(cnt[T] == K){
			return top.d;
		}

		for (int i = HEAD[top.v]; ~i; i = e[i].next) {
			int v = e[i].v;
			int w = e[i].w;
			if(cnt[v] < K){
				q.push(node {dis[v]+w+top.d,v,top.d + w});
			}
		}
	}
	return -1;
}

int main() {
	init();
	int n,m;
	int u,v,w;

	cin>>n>>m;
	while(m--) {

		cin>>u>>v>>w;
		insertD(HEAD,u,v,w);
		insertD(HEADC,v,u,w);	// build two-direction graph.

	}
	cin>>S>>T>>K;
	//case ensure S != T:
	Dijkstra(T);
	cout<<Astar(S)<<endl;

	return 0;
}


