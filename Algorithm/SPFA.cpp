#include <iostream>
#include <cstring>
#include <queue>


using namespace std;

const int N = 1e3 + 9;
const int M = 1e4 + 9;
const int inf = 0x3f3f3f3f;

struct edge{
	int v;
	int w;
	int fail;
	edge(){
	}
	edge(int _v , int _w , int _fail){
		v = _v;
		w = _w;
		fail = _fail;
	}
	
}e[ M << 1];	// equal with "*2"

int head[N],len;

void init(){
	
	memset(head,-1,sizeof(head));	// '-1' end flag.
	len = 0;
}

void insertD(int u, int v ,int w){
	e[len] = edge(v,w,head[u]);	// create linked list.
	head[u] = len++;
}

void insertUD(int u, int v ,int w){
	insertD(u,v,w);
	insertD(v,u,w);
}
int n,m;
int dis[N],times[N];
bool vis[N];	// node is in queue or not.

bool  SPFA(int src){
	
	memset(dis,0x3f,sizeof(dis));
	memset(vis,false,sizeof(vis));
	memset(times,0,sizeof(times));
	dis[src] = 0;
	vis[src] = true;
	times[src] = 1;
	
	queue<int>	que;
	que.push(src);
	
	while(!que.empty()){
		
		src = que.front();
		que.pop();
		vis[src] = false;
		
		for(int j= head[src]; ~j; j = e[j].fail){
			
			int v = e[j].v;
			int w = e[j].w;
			
			if(dis[v] > dis[src] + w){
				
				dis[v] = dis[src] + w;
				
				if(!vis[v]){
					que.push(v);
					vis[v] = true;
					times[v]++;
					if(times[v] > n) return true;
				}
			}
		}
	}
	
	return false;
	
}

int main(){
	// BUT SPFA can't use for the graph has negative loop
	// can use SPFA to judge there exist negative loop or not.
	// JUFGE: one node inter the queue numbers, bigger than total node's num 'n';
	init();
	cin>>n>>m;
	
	while(m--){
		
		int u,v,w;
		cin>>u>>v>>w;
		
		insertUD(u,v,w);
	}
	
	if(SPFA(1)){
		cout<<"yes"<<endl;
	}else{
		cout<<"no"<<endl;
		cout<<dis[n]<<endl;
	}
	
	
	return 0;
}