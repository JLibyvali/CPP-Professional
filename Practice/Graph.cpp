#include <iostream>
#include <vector>


using namespace std;
// weighted graph
//
//struct node{
//	int v;	// dot
//	int w;	// len 
//};
//
//vector<node> G[11];	// When decalre in global variable, it will auto zero-initialized.
//
//void insertD(int u,int v,int w){
//	node tmp;	// using the adjacency table
//	tmp.v = v;
//	tmp.w =w;
//	G[u].push_back(tmp);
//}
//void insertUD(int u,int v,int w){
//	insertD(u,v,w);
//	insertD(v,u,w);
//}

// use the linked list

const int N = 1001;
const int M = 10001;


// using the adjacency list to describe graph
// edge is the num of every node's linked-list edges.

struct edge{
	int v;	//	edge's destination
	int w;	// edge's weight
	int next;	// point to next edge serial number , '-1' means end .
	
	edge(){}
	
	edge(int _v,int _w,int _next ){
		v = _v;
		w = _w;
		next = _next;
	}
	
}e[ M*2 ];	//every edge

int head[N];	// means the linked list head node, '-1' is end-flag, 
//index is node's order, value is the linked list edges num;
int size;	// total graph edge numbers.

void init(){
	memset(head,-1,sizeof(head));	// no node has edges, must initial '-1'
	size = 0;
}
void insertD(int u, int v ,int w){
	
	e[size] = edge(v,w,head[u]);	// linked list 'u' 
	head[u] = size++;	// "struct edge" initialize one, in that linked list , the edges num upper.	
	
}

void insertUD(int u,int v,int w){
	insertD(u,v,w);
	insertD(v,u,w);
}

int n,m;


int dis[N];	// Dijkstra's src node to every node's destinction
bool vis[N];	// ndoe has marked or not

void Dijkstra(int src){
	
	memset(vis,false,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));	// by bytes order to write, every bytes maxnum with +- bit : 0x7f.	
	
	
	dis[src] = 0;	
	
	for(int i=0;i<n;i++){
		
		int mind = 1e10, minj = -1;
		
		for(int j=1;j<=n;j++){
			
			if(!vis[j]&& dis[j]<mind){
				minj = j;
				mind = dis[j];
			}
		}
		if(minj = -1) return;
		
		vis[minj] = true;
		for(int j=head[minj];~j;j = e[j].next){	// ~j: also and only means j != -1;
		// When j==1, also j==0xffffffffffffffff, so ~j == 0==false;
			
			int v = e[j].v;
			int w = e[j].w;
			
			if(!vis[v] && dis[v] > dis[minj] + w){
				dis[v] = dis[minj] = 
			}
			
		}
	}
	
	
}
int  main(){
	// directed graph and undirected graph
		
//	int m;
//	cin >>m;	// insert undirected graph
//	for(int i=0;i<m;i++){
//		int u,v,w;
//		cin>>u>>v>>w;
//		insertUD(u,v,w);
//	}
//	
//	for(int i=0;i<11;i++){
//		for(const auto& ele:G[i]){
//			cout<<"("<<i<<","<<ele.v<<","<<ele.w<<")";
//		}
//		cout<<endl;
//	}
	
	// but use this way, the 'vector' const-num was too big, so usually use linked-list .
	init();
	
	cin>>n>>m;
	int u,v,w;
		cin>>u>>v>>w;
		insertUD(u,v,w);
	}
	
	Dijkstra(1);

	return 0;
}
